#!/usr/bin/node
$(function (){
	$('#add_button').click( () => {
		$('#form').html('<p>Title: <input id="title" placeholder="Title"></p><p>Description: <input id="description" placeholder="Description"></input></p><button id="submitb">Create Task</button>')
	});
});
const title = $('#title').val()
const description = $('#description').val()

$('#submitb').click( () => {
	var myDict = {
		"title": title,
		"description": description,
		"category_id": 358b348c-2cbf-4c04-bfbf-06a442db5913,
		"user_id": ec3aae58-091b-4672-8670-99fec089052f,
	};
	$.ajax({
		type: 'POST',
		url: 'http://0.0.0.0:8000/todo/tasks',
		data: JSON.stringify(myDict),
		contentType: 'application/json',
		dataType: 'json',
		success: function(newDict) {
			alert(newDict.title + ' has been created successfully');
		},
		error: function() {
			alert("An error has occured");
		},
	});
});
