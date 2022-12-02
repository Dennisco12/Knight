#!/usr/bin/node
$('document').ready(function () {
	const api = 'http://' + window.location.hostname;
	$('button.add').click( () => {
		$('div.form').append('<input class="title"></input><input class="description"></input>')
}

$.ajax({
	url: api + ':5000/api/tasks',
	type: 'POST',
	data: {},
	contentType: 'application/json',
	dataType: 'json',
});
