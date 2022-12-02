#!/usr/bin/node
$('document').ready(function () {
	const api = 'http://' + window.location.hostname;
	$('button.add').click( () => {
		$('div.form').append('<p>Title: <input class="title"></p><p>Description: </input><input class="description"></input></p><button class="submit"></button>')
	});
	const title = $('div.form input.title').val
	const description = $('div.form input.description').val
	$('div.form button.submit').click( () => {
		const myDict = {title: decription};
		function addTask(myDict)
	});
});

$('div.form button.submit').click(addTask(myDict) {
	$.ajax({
		url: api + ':5000/api/tasks',
		type: 'POST',
		data: JSON.stringify(myDict),
		contentType: 'application/json',
		dataType: 'json',
	});
});
