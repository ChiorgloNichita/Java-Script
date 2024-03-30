const transactions = require('./transaction1.json');

class TransactionAnalyzer {
    constructor(transactionsArray) {
        this.transactions = transactionsArray; // Инициализация массива транзакций
    }

    // Метод для получения уникальных типов транзакций
    getUniqueTransactionType() {
        const uniqueTransactionType = new Set(); // Создание Set для хранения уникальных типов
        this.transactions.forEach((transaction) => { // Итерация по всем транзакциям
            uniqueTransactionType.add(transaction.transaction_type); // Добавление типа транзакции в Set
        });
        return [...uniqueTransactionType]; // Преобразование Set обратно в массив и возврат
    }

    // Метод для рассчета общей суммы всех транзакций
    calculateTotalAmount() {
        return this.transactions.reduce((acc, val) => acc + val.transaction_amount, 0); // Использование reduce для суммирования всех сумм
    }

    // Метод для вычисления общей суммы транзакций за указанный год, месяц и день
    calculateTotalAmountByDate(year, month, day) {
        const date = new Date(year, month - 1, day); // Создание объекта Date на основе переданных параметров
        return this.transactions.reduce((acc, val) => { // Использование reduce для суммирования сумм транзакций за указанную дату
            const transactionDate = new Date(val.transaction_date); // Получение даты транзакции
            if (
                transactionDate.getDate() === date.getDate() && // Проверка на совпадение даты
                transactionDate.getMonth() === date.getMonth() && // Проверка на совпадение месяца
                transactionDate.getFullYear() === date.getFullYear() // Проверка на совпадение года
            ) {
                return acc + val.transaction_amount; // Если транзакция соответствует указанной дате, добавляем ее сумму к общей сумме
            }
            return acc; 
        }, 0);
    }

    // Метод для получения транзакций указанного типа (debit или credit)
    getTransactionByType(type) {
        return this.transactions.filter((transaction) => transaction.transaction_type === type); // Фильтрация массива транзакций по типу
    }

    // Метод для получения транзакций, проведенных в указанном диапазоне дат
    getTransactionsInDateRange(startDate, endDate) {
        return this.transactions.filter((transaction) => { // Фильтрация массива транзакций
            const transactionDate = new Date(transaction.transaction_date); // Получение даты транзакции
            return transactionDate >= startDate && transactionDate <= endDate; // Проверка на попадание в заданный диапазон дат
        });
    }

    // Метод для получения транзакций, совершенных с указанным торговым местом или компанией
    getTransactionsByMerchant(merchantName) {
        return this.transactions.filter((transaction) => transaction.merchant_name === merchantName); // Фильтрация массива транзакций по имени мерчанта
    }

    // Метод для вычисления среднего значения суммы транзакций
    calculateAverageTransactionAmount() {
        return this.calculateTotalAmount() / this.transactions.length; // Расчет среднего значения суммы
    }

    // Метод для получения транзакций с суммой в заданном диапазоне
    getTransactionsByAmountRange(minAmount, maxAmount) {
        return this.transactions.filter((transaction) => { // Фильтрация массива транзакций по диапазону сумм
            return transaction.transaction_amount >= minAmount && transaction.transaction_amount <= maxAmount;
        })
    }

    // Метод для вычисления общей суммы дебетовых транзакций
    calculateTotalDebitAmount() {
        return this.transactions.reduce((acc, val) => { // Использование reduce для суммирования сумм дебетовых транзакций
            if (val.transaction_type === 'debit') { // Проверка типа транзакции
                return acc + val.transaction_amount; // Если тип дебетовый, добавляем сумму к общей сумме
            }
            return acc; 
        }, 0);
    }

    // Метод для нахождения месяца с наибольшим количеством транзакций
    findMostTransactionsMonth(arr) {
        const monthCount = {}; // Создание объекта для подсчета количества транзакций в каждом месяце
        if (arr === undefined) { // Проверка на наличие аргумента arr
            arr = this.transactions; // Если аргумент не передан, используем весь массив транзакций
        }

        arr.forEach((transaction) => { // Итерация по массиву транзакций
            const month = new Date(transaction.transaction_date).getMonth() + 1; // Получение номера месяца

            if (month in monthCount) { // Проверка наличия месяца в объекте monthCount
                monthCount[month] += 1; // Если месяц уже присутствует, увеличиваем счетчик на 1
            } else {
                monthCount[month] = 1; // Если месяц новый, инициализируем счетчик значением 1
            }
        });

        const maxTransactionCount = Math.max(...Object.values(monthCount)); // Находим максимальное количество транзакций
        const mostTransactionsMonth = Object.entries(monthCount) // Получаем массив пар [ключ, значение]
            .filter(([month, count]) => count === maxTransactionCount) // Фильтруем массив, оставляя только пары с максимальным количеством транзакций
            .map(([month]) => parseInt(month)); // Преобразуем номера месяцев обратно в числа

        return mostTransactionsMonth.length === 1 ? mostTransactionsMonth[0] : mostTransactionsMonth; // Возвращаем номер месяца или массив номеров месяцев с наибольшим количеством транзакций
    }

    // Метод для нахождения месяца с наибольшим количеством дебетовых транзакций
    findMostDebitTransactionMonth() {
        return this.findMostTransactionsMonth(this.transactions.filter((transaction) => transaction.transaction_type === 'debit')); 
    }

    // Метод для определения, какой тип транзакций (дебетовые или кредитовые) встречается чаще
    mostTransactionTypes() {
        const debitLength = this.transactions.filter((transaction) => transaction.transaction_type === 'debit').length; // Количество дебетовых транзакций
        const creditLength = this.transactions.filter((transaction) => transaction.transaction_type === 'credit').length; // Количество кредитовых транзакций

        if (debitLength === creditLength) { // Сравнение количества дебетовых и кредитовых транзакций
            return 'equal'; // Если количества равны, возвращаем 'equal'
        }
        return debitLength > creditLength ? 'debit' : 'credit'; // Если дебетовых больше, возвращаем 'debit', иначе 'credit'
    }

    // Метод для получения транзакций, совершенных до указанной даты
    getTransactionsBeforeDate(date) {
        return this.transactions.filter((transaction) => {
            return transaction.transaction_date < date; // Фильтрация транзакций, проведенных до указанной даты
        });
    }

    // Метод для поиска транзакции по ее уникальному идентификатору
    findTransactionById(id) {
        const transaction = this.transactions.find((transaction) => transaction.transaction_id === id); 
        return transaction || {}; 
    }

    // Метод для получения массива описаний транзакций
    mapTransactionDescriptions() {
        return this.transactions.map((transaction) => transaction.transaction_description); // Извлечение описаний из массива транзакций и возврат нового массива
    }
}

