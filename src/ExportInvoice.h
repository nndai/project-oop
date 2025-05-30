#ifndef EXPORT_INVOICE_H_
#define EXPORT_INVOICE_H_

#include "Order.h"
#include "Customer.h"
#include "TableUI.h"
#include <string>
#include <fstream>

/**
 * @file ExportInvoice.h
 * @brief Định nghĩa lớp ExportInvoice để xuất hóa đơn cho đơn hàng và khách hàng.
 */

/**
 * @class ExportInvoice
 * @brief Lớp chịu trách nhiệm xuất hóa đơn cho đơn hàng và khách hàng.
 *       Cung cấp phương thức để xuất thông tin đơn hàng và khách hàng ra file.
 */
class ExportInvoice {
public:
    /**
     * @brief Xuất hóa đơn cho đơn hàng và khách hàng.
     * @param order Đơn hàng cần xuất hóa đơn.
     * @param customer Khách hàng liên quan đến đơn hàng.
     * @return true nếu xuất hóa đơn thành công, false nếu không thành công.
     */
    static bool exportInvoiceToFile(const Order& order, const Customer& customer, const std::string& filename);
};

#endif
