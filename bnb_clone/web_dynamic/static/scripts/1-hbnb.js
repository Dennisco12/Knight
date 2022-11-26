#!/usr/bin/node
window.onload = () => {
	let myDict = {};
	$('INOUT[type="checkbox"]').change(() => {
		if ($(this).is(':checked')) {
			myDict[$(this).attr('data-id')] = $(this).attr('data-name');
		} else {
			delete myDict[$(this).attr('data-id')];
		}
		$('.amenities H4').text(Object.values(myDict).join(', '));
	});
};
