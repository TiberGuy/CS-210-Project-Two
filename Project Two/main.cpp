#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

//class that calculates investment growth over time
class InvestmentCalculator {
public:
    //constructor that sets initial values
    InvestmentCalculator(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate, int t_numYears)
        : m_initialInvestment(t_initialInvestment),
          m_monthlyDeposit(t_monthlyDeposit),
          m_annualInterestRate(t_annualInterestRate),
          m_numYears(t_numYears) {}

    //generates both investment reports
    void generateReports() {
        displayReportWithoutMonthlyDeposits();
        std::cout << std::endl;
        displayReportWithMonthlyDeposits();
    }

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int m_numYears;

    //report showing yearly growth with no monthly deposits
    void displayReportWithoutMonthlyDeposits() {
        std::cout << "\n  Balance and Interest Without Additional Monthly Deposits\n";
        std::cout << "============================================================\n";
        std::cout << std::left
                  << std::setw(6) << "Year"
                  << std::setw(25) << "Year End Balance"
                  << std::setw(25) << "Year End Earned Interest"
                  << std::endl;

        double balance = m_initialInvestment;

        //simulate compounding interest for each year
        for (int year = 1; year <= m_numYears; ++year) {
            double yearlyInterest = 0.0;
            for (int month = 0; month < 12; ++month) {
                double monthlyInterest = balance * (m_annualInterestRate / 100.0) / 12.0;
                balance += monthlyInterest;
                yearlyInterest += monthlyInterest;
            }

            //print yearly summary
            std::cout << std::left
                      << std::setw(6) << year
                      << "$" << std::setw(24) << std::fixed << std::setprecision(2) << balance
                      << "$" << std::setw(24) << yearlyInterest
                      << std::endl;
        }
    }

    //report showing yearly growth with additional monthly deposits
    void displayReportWithMonthlyDeposits() {
        std::cout << "\n  Balance and Interest With Additional Monthly Deposits\n";
        std::cout << "============================================================\n";
        std::cout << std::left
                  << std::setw(6) << "Year"
                  << std::setw(25) << "Year End Balance"
                  << std::setw(25) << "Year End Earned Interest"
                  << std::endl;

        double balance = m_initialInvestment;

        //simulate compounding with deposits for each year
        for (int year = 1; year <= m_numYears; ++year) {
            double yearlyInterest = 0.0;
            for (int month = 0; month < 12; ++month) {
                balance += m_monthlyDeposit;
                double monthlyInterest = balance * (m_annualInterestRate / 100.0) / 12.0;
                balance += monthlyInterest;
                yearlyInterest += monthlyInterest;
            }

            //print yearly summary
            std::cout << std::left
                      << std::setw(6) << year
                      << "$" << std::setw(24) << std::fixed << std::setprecision(2) << balance
                      << "$" << std::setw(24) << yearlyInterest
                      << std::endl;
        }
    }
};

int main() {
    double initialInvestment, monthlyDeposit, annualInterestRate;
    int numYears;

    //welcome message
    std::cout << "Welcome to the Airgead Banking Investment Calculator!\n\n";

    //display input header
    std::cout << "**********************************\n";
    std::cout << "********** Data Input ************\n";
    std::cout << "**********************************\n";

    //collect user input with validation
    std::cout << "Initial Investment Amount: $";
    std::cin >> initialInvestment;
    while (initialInvestment < 0) {
        std::cout << "Please enter a positive amount: $";
        std::cin >> initialInvestment;
    }

    std::cout << "Monthly Deposit: $";
    std::cin >> monthlyDeposit;
    while (monthlyDeposit < 0) {
        std::cout << "Please enter a positive amount: $";
        std::cin >> monthlyDeposit;
    }

    std::cout << "Annual Interest (%): ";
    std::cin >> annualInterestRate;
    while (annualInterestRate < 0) {
        std::cout << "Please enter a positive interest rate: ";
        std::cin >> annualInterestRate;
    }

    std::cout << "Number of Years: ";
    std::cin >> numYears;
    while (numYears < 1) {
        std::cout << "Please enter a number greater than 0: ";
        std::cin >> numYears;
    }

    //wait before displaying report
    std::cout << "Press any key to continue . . .";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    std::cout << std::endl;

    //create calculator object and generate both reports
    InvestmentCalculator calculator(initialInvestment, monthlyDeposit, annualInterestRate, numYears);
    calculator.generateReports();

    return 0;
}
