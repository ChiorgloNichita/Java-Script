// Импорт функции getRandomActivity из модуля activity.js
import { getRandomActivity } from './activity.js';

// Асинхронная функция updateActivity, которая обновляет активность
async function updateActivity() {
    try {
        // Получение случайной активности с помощью функции getRandomActivity
        const activity = await getRandomActivity();
        // Вывод полученной активности в консоль
        console.log('Activity:', activity);
    } catch (error) {
        // Обработка ошибок при получении активности
        console.error('Error fetching activity:', error.message);
    } finally {
        // Установка таймера для следующего обновления активности через минуту
        setTimeout(updateActivity, 60000);
    }
}

// Вызов функции updateActivity при загрузке страницы для получения начальной активности
updateActivity();
