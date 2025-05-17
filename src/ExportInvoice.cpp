#include "ExportInvoice.h" 

bool ExportInvoice::exportInvoiceToFile(const Order& order, const Customer& customer, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return false;
    }
    file << "===== INVOICE =====\n";
    file << "Customer: " << customer.getName() << " (" << customer.getType() << ")\n";
    file << "Order ID: " << order.getId() << "\n";
    file << "Order Date: " << order.getOrderDate() << "\n";
    std::vector<std::vector<std::string>> tuples;
    tuples.push_back({ "ItemID", "Name", "Quantity", "Price", "Total" });
    
    double total = 0;
    for (const auto& detail : order.getOrderDetails()) {
        
        double line_total = detail.quantity * detail.price;
        tuples.push_back({ std::to_string(detail.music_id), detail.music_name, std::to_string(detail.quantity), std::to_string(detail.price), std::to_string(line_total) });
        total += line_total;
    }

    TableUI::print(file, tuples);
    file << "\nTotal: $" << total << "\n";
    file.close();
    return true;
}