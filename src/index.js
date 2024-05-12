import { getRandomActivity } from './activity.js';

/**
 * Обновляет активность с интервалом в минуту, используя функцию getRandomActivity.
 */
async function updateActivity() {
    try {
        // Получение случайной активности с помощью функции getRandomActivity
        const activity = await getRandomActivity();
        // Обновление содержимого элемента с идентификатором "activity" новой активностью
        document.getElementById('activity').innerText = activity;
    } catch (error) {
        // Обработка ошибок при получении активности
        console.error('Error fetching activity:', error.message);
    } finally {
        // Установка таймера для следующего обновления активности через минуту
        document.addEventListener("DOMContentLoaded", function() {
            setTimeout(updateActivity, 1000); // Задержка в 1 секунду перед вызовом updateActivity()
        });
        
    }
}

// Вызов функции updateActivity при загрузке страницы для получения начальной активности
updateActivity();
