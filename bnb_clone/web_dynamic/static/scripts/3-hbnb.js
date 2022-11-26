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
$.ajax({
	type: 'POST',
	url: 'http://5001/api/v1/places_search/',
	Content-Type: 'application/json',
	data: '{}',
	success: (data, textStatus) => {
		$(section.places).append(data.map(place => {
			return `<article>
          <div class="title_box">
            <h2>{{ place.name }}</h2>
            <div class="price_by_night">${{ place.price_by_night }}</div>
          </div>
          <div class="information">
            <div class="max_guest">{{ place.max_guest }} Guest{% if place.max_guest != 1 %}s{% endif %}</div>
            <div class="number_rooms">{{ place.number_rooms }} Bedroom{% if place.number_rooms != 1 %}s{% endif %}</div>
            <div class="number_bathrooms">{{ place.number_bathrooms }} Bathroom{% if place.number_bathrooms != 1 %}s{% endif %}</div>
          </div>
          <div class="user">
            <b>Owner:</b> {{ place.user.first_name }} {{ place.user.last_name }}
          </div>
          <div class="description">
            {{ place.description | safe }}
          </div>
        </article>`;
	    }));
	};
});
