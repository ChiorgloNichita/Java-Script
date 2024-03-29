const transactions = require('./transaction1.json');

class TransactionAnalyzer {
    constructor(transactionsArray) {
        this.transactions = transactionsArray;
    }

    addTransactions(transaction) {
        this.transactions.push(transaction);
    }

    getAllTransactions() {
        return this.transactions;
    }

    addToAllString() {
        this.transactions.forEach((transaction) => {
            if (!('string' in transaction)) {
                transaction.string = () => JSON.stringify(transaction);
            }
        });
    }

    getUniqueTransactionType() {
        const uniqueTransactionType = new Set();
        this.transactions.forEach((transaction) => {
            uniqueTransactionType.add(transaction.transaction_type);
        });
        return [...uniqueTransactionType];
    }

    calculateTotalAmount() {
        return this.transactions.reduce((acc, val) => acc + val.transaction_amount, 0);
    }

    calculateTotalAmountByDate(year, month, day) {
        const date = new Date(year, month - 1, day);
        return this.transactions.reduce((acc, val) => {
            const transactionDate = new Date(val.transaction_date);
            if (
                transactionDate.getDate() === date.getDate() &&
                transactionDate.getMonth() === date.getMonth() &&
                transactionDate.getFullYear() === date.getFullYear()
            ) {
                return acc + val.transaction_amount;
            }
            return acc;
        }, 0);
    }

    getTransactionByType(type) {
        return this.transactions.filter((transaction) => transaction.transaction_type === type);
    }

    getTransactionsInDateRange(startDate, endDate) {
        return this.transactions.filter((transaction) => {
            const transactionDate = new Date(transaction.transaction_date);
            return transactionDate >= startDate && transactionDate <= endDate;
        });
    }

    getTransactionsByMerchant(merchantName) {
        return this.transactions.filter((transaction) => transaction.merchant_name === merchantName);
    }

    calculateAverageTransactionAmount() {
        return this.calculateTotalAmount() / this.transactions.length;
    }

    getTransactionsByAmountRange(minAmount, maxAmount) {
        return this.transactions.filter((transaction) => transaction.transaction_amount >= minAmount && transaction.transaction_amount <= maxAmount);
    }

    calculateTotalDebitAmount() {
        return this.transactions.reduce((acc, val) => {
            if (val.transaction_type === 'debit') {
                return acc + val.transaction_amount;
            }
            return acc;
        }, 0);
    }

    findMostTransactionsMonth(arr) {
        const monthCount = {};
        if (arr === undefined) {
            arr = this.transactions;
        }

        arr.forEach((transaction) => {
            const month = new Date(transaction.transaction_date).getMonth() + 1;

            if (month in monthCount) {
                monthCount[month] += 1;
            } else {
                monthCount[month] = 1;
            }
        });

        const maxTransactionCount = Math.max(...Object.values(monthCount));
        const mostTransactionsMonth = Object.entries(monthCount)
            .filter(([month, count]) => count === maxTransactionCount)
            .map(([month]) => parseInt(month));

        return mostTransactionsMonth.length === 1 ? mostTransactionsMonth[0] : mostTransactionsMonth;
    }

    findMostDebitTransactionMonth() {
        return this.findMostTransactionsMonth(this.transactions.filter((transaction) => transaction.transaction_type === 'debit'));
    }

    mostTransactionTypes() {
        const debitLength = this.transactions.filter((transaction) => transaction.transaction_type === 'debit').length;
        const creditLength = this.transactions.filter((transaction) => transaction.transaction_type === 'credit').length;

        if (debitLength === creditLength) {
            return 'equal';
        }
        return debitLength > creditLength ? 'debit' : 'credit';
    }

    getTransactionsBeforeDate(date) {
        if (!(date instanceof Date) || isNaN(date)) {
            throw new Error('Invalid date provided');
        }
        return this.transactions.filter((transaction) => new Date(transaction.transaction_date) < date);
    }

    findTransactionById(id) {
        const transaction = this.transactions.find((transaction) => transaction.transaction_id === id);
        return transaction || {};
    }

    mapTransactionDescriptions() {
        return this.transactions.map((transaction) => transaction.transaction_description);
    }
}

const analyzer = new TransactionAnalyzer(transactions);
analyzer.addToAllString();

// console.log(analyzer.getUniqueTransactionType('debit'));
// console.log(analyzer.calculateTotalAmount());
// console.log(analyzer.calculateTotalAmountByDate(2019, 4, 30));
// console.log(analyzer.getTransactionByType('credit'));
// console.log(analyzer.getTransactionsInDateRange(new Date('2019-04-28'), new Date())) 
// console.log(analyzer.getTransactionsByMerchant('DoughnutShop789'));
// console.log(analyzer.calculateAverageTransactionAmount());
// console.log(analyzer.getTransactionsByAmountRange(80,100));
// console.log(analyzer.calculateTotalDebitAmount());
// console.log(analyzer.findMostTransactionsMonth());
// console.log(analyzer.findMostDebitTransactionMonth());
// console.log(analyzer.mostTransactionTypes());
// console.log(analyzer.getTransactionsBeforeDate(new Date('2019-01-06')))
// console.log(analyzer.findTransactionById(26))
// console.log(analyzer.mapTransactionDescriptions());
