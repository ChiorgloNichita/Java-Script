/**
 * Массив транзакций.
 * @type {Array<Object>}
 */
let transactions = [];

/**
 * Добавляет новую транзакцию.
 * @param {Event} event - Событие отправки формы.
 */
function addTransaction(event) {
    event.preventDefault();

    // Получаем данные из формы
    const form = event.target;
    const date = form.date.value;
    const amount = parseFloat(form.amount.value);
    const category = form.category.value;
    const description = form.description.value;

    // Генерируем уникальный идентификатор для новой транзакции
    const id = transactions.length + 1;

    // Создаем объект транзакции
    const transaction = { id, date, amount, category, description };

    // Добавляем транзакцию в массив
    transactions.push(transaction);

    // Добавляем строку в таблицу для отображения новой транзакции
    const table = document.getElementById('transaction-table').getElementsByTagName('tbody')[0];
    const row = table.insertRow();
    row.innerHTML = `<td>${id}</td><td>${date}</td><td>${category}</td><td>${description.substring(0, 50)}</td><td><button onclick="deleteTransaction(${id})">Удалить</button></td>`;
    row.style.color = amount >= 0 ? 'green' : 'red';

    // Пересчитываем общую сумму транзакций
    calculateTotal();
}

/**
 * Удаляет транзакцию по её идентификатору.
 * @param {number} id - Идентификатор транзакции для удаления.
 */
function deleteTransaction(id) {
    // Фильтруем массив транзакций, оставляя только те, у которых id не совпадает с переданным
    transactions = transactions.filter(transaction => transaction.id !== id); 

    // Удаляем строку из таблицы
    document.getElementById('transaction-table').deleteRow(id); 

    // Пересчитываем общую сумму транзакций
    calculateTotal(); 
}

/**
 * Вычисляет общую сумму всех транзакций и обновляет соответствующий элемент на странице.
 */
function calculateTotal() {
    // Получаем элемент, в который будем выводить общую сумму
    const totalElement = document.getElementById('total');
    
    // Суммируем все транзакции
    const totalAmount = transactions.reduce((total, transaction) => total + transaction.amount, 0);
    
    // Обновляем текст элемента с общей суммой
    totalElement.textContent = `Общая сумма: ${totalAmount}`;
}

/**
 * Показывает подробности о выбранной транзакции.
 * @param {number} id - Идентификатор выбранной транзакции.
 */
function showTransactionDetails(id) {
    // Находим транзакцию по её идентификатору
    const transaction = transactions.find(transaction => transaction.id === id);
    
    // Получаем элемент, в который будем выводить подробности о транзакции
    const detailsElement = document.getElementById('transaction-details');
    
    // Выводим подробности о транзакции
    detailsElement.innerHTML = `<h2>Подробности транзакции #${id}</h2>
                                <p><strong>Дата и время:</strong> ${transaction.date}</p>
                                <p><strong>Сумма:</strong> ${transaction.amount}</p>
                                <p><strong>Категория:</strong> ${transaction.category}</p>
                                <p><strong>Описание:</strong> ${transaction.description}</p>`;
}

// Обработчик события отправки формы для добавления транзакции
document.getElementById('transaction-form').addEventListener('submit', addTransaction);

// Обработчик события клика для отображения подробностей о транзакции
document.getElementById('transaction-table').addEventListener('click', function(event) {
    const target = event.target;
    if (target.tagName === 'TD') {
        const row = target.parentElement;
        const id = parseInt(row.cells[0].textContent);
        showTransactionDetails(id);
    }
});
