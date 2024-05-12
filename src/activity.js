/**
 * Получает случайную активность с помощью запроса к API.
 * @returns {Promise<string>} Строка с описанием случайной активности.
 * @throws {Error} Если не удалось получить активность.
 */
export async function getRandomActivity() {
    try {
        // Отправка запроса к API
        const response = await fetch('https://www.boredapi.com/api/activity/');
        // Проверка успешности ответа
        if (!response.ok) {
            // В случае ошибки выбрасывается исключение
            throw new Error('Failed to fetch activity');
        }
        // Получение данных из ответа в формате JSON
        const data = await response.json();
        // Возвращение активности из полученных данных
        return data.activity;
    } catch (error) {
        // Обработка ошибок при запросе активности
        throw new Error('Failed to fetch activity');
    }
}
