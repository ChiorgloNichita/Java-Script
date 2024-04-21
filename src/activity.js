/**
 * Асинхронная функция, которая делает запрос к API для получения случайной активности.
 * @async
 * @function getRandomActivity
 * @returns {Promise<string>} Случайная активность
 */
async function getRandomActivity() {
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

// Экспорт функции getRandomActivity для использования в других модулях
export { getRandomActivity };