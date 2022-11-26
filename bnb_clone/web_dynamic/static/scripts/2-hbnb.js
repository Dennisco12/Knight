#!/usr/bin/node
window.onload = () => {
	let myDict = {};
	$('INPUT[type="checkbox"]').change(() => {
		if ($(this).is(':checked')) {
			myDict[$(this).attr('data-id')] = $(this).attr('data-name');
		} else {
			delete myDict[$(this).attr('data-id')];
		}
		$('.amenities H4').text(Object.values(myDict).join(', '));
	});
};
$.ajax({
	type: 'GET',
	url: 'http://0.0.0.0:5001/api/vi/status/',
	success: (data, textStatus) => {
		if (textStatus === 'OK') {
			$('DIV#api_status').addClass('available')
		} else {
			$('DIV#api_status').removeClass('available')
		}
	}
});
