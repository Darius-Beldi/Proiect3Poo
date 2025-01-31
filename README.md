# Pharmacy Management System

A comprehensive C++ application for managing a pharmacy's inventory and sales operations. This system handles different types of medications, prescriptions, and generates detailed receipts for transactions.

## Features

### Medication Management
- Support for multiple medication types:
  - Regular medications
  - Anti-inflammatory medications
  - Dietary supplements
  - Prescription anti-inflammatory medications
- Complete inventory tracking with stock management
- Flexible pricing system
- Prescription code verification for restricted medications

### Sales Processing
- Interactive menu-driven interface
- Real-time inventory updates
- Automated receipt generation
- Customer information management
- Multiple pharmacy location support

### Data Management
- File-based data persistence
- Support for both manual and file-based data input
- Receipt archiving system
- Flexible data import/export capabilities

## Technical Implementation

### Class Hierarchy
```
IOInterface (Abstract)
└── Medicament (Base)
    ├── Antiinflamator
    │   └── AntiinflamatorCuReteta
    └── Suplimentalimentar
```

### Key Classes
- **Medicament**: Base class for all medication types
- **Antiinflamator**: Specialized class for anti-inflammatory medications
- **Suplimentalimentar**: Handles dietary supplements
- **AntiinflamatorCuReteta**: Manages prescription anti-inflammatory medications
- **Bon**: Handles receipt generation and transaction management
- **Meniu**: Singleton class managing the user interface and program flow

### Design Patterns
- Singleton Pattern: Used in the Menu implementation
- Factory Pattern: Implemented for medication creation
- Strategy Pattern: Applied in the receipt generation system

## Getting Started

### Prerequisites
- C++ compiler with C++11 support or higher
- Standard Template Library (STL)
- File system support

### File Structure
```
project/
├── src/
│   └── main.cpp
├── bonuri/
│   └── [generated receipts]
└── data/
    └── [medication data files]
```

### Building the Project
1. Compile the source code:
   ```bash
   g++ -std=c++11 main.cpp -o pharmacy
   ```
2. Run the executable:
   ```bash
   ./pharmacy
   ```

### Data File Format
Medication data files should follow this format:
```
type,name,price,stock,[additional fields]
```
Types:
1. Dietary Supplement: `1,name,price,stock,vitamin1,vitamin2,...`
2. Anti-inflammatory: `2,name,price,stock,substance`
3. Prescription Anti-inflammatory: `3,name,price,stock,substance,prescriptionCode`

## Usage

1. Start the program
2. Choose data input method (file/manual)
3. Enter customer information
4. Select pharmacy location
5. Process transactions:
   - Add medications to cart
   - Verify prescriptions when required
   - Generate receipts
   - Track inventory

## Features in Detail

### Inventory Management
- Real-time stock tracking
- Automatic stock updates on sales
- Low stock alerts
- Support for multiple medication categories

### Transaction Processing
- Itemized receipts
- Multiple payment methods
- Prescription verification
- Customer record management

### Data Handling
- Secure prescription code verification
- Customer data management
- Transaction history
- Stock level monitoring

## Error Handling

The system includes comprehensive error handling for:
- Invalid input validation
- Stock availability checks
- Prescription verification
- File operations
- Data format validation
