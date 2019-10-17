<?php
/**
 * Implementation of hook_audiofield_players().
 */
function audiofield_players() {
  $players = module_invoke_all('audiofield_players');
  $players_dir = config_get('audiofield.settings', 'players_dir');

  $players['html5'] = array(
    'name' => 'HTML5 <audio>',
    'filetypes' => array('mp3', 'wav', 'ogg'),
    'local' => TRUE,
    'callback' => 'audiofield_html5_audio',
  );

  $players['wpaudioplayer'] = array(
    'path' => $players_dir . "/audio-player/player.swf",
    'name' => 'WordPress Audio Player',
    'download_link' => 'http://wpaudioplayer.com/download',
    'filetypes' => array('mp3'),
    'callback' => 'audiofield_wpaudioplayer',
  );

  $players['xspf_slim'] = array(
    'path' => $players_dir . "/xspf_player_slim.swf",
    'name' => 'XSPF Slim Player',
    'download_link' => 'http://prdownloads.sourceforge.net/musicplayer/xspf_player_slim-correct-0.2.3.zip?download',
    'filetypes' => array('mp3'),
    'callback' => 'audiofield_xspf_slim',
  );

  $players['xspf_button'] = array(
    'path' => $players_dir . "/button/musicplayer.swf",
    'name' => 'XSPF Button Player',
    'download_link' => 'http://prdownloads.sourceforge.net/musicplayer/button_player-0.1.zip?download',
    'filetypes' => array('mp3'),
    'callback' => 'audiofield_xspf_button',
  );

  //#1414398: Premium Beat players no longer available
  $players['premium_beat_single_track'] = array(
    'path' => $players_dir . "/playerSinglePackage/playerSingle.swf",
    'name' => 'Premium Beat Single Player',
    //'download_link' => 'http://www.premiumbeat.com/flash_resources/free_flash_music_player/single_track_flash_mp3_player.php',
    'filetypes' => array('mp3'),
    'callback' => 'audiofield_premium_beat_single_track',
  );

  $players['premium_beat_thin'] = array(
    'path' => $players_dir . "/OriginalThinMusicPlayer.swf",
    'name' => 'Premium Beat Thin Player',
    //'download_link' => 'http://www.premiumbeat.com/flash_music_players/original/thin/',
    'filetypes' => array('mp3'),
    'callback' => 'audiofield_premium_beat_thin',
  );

  $players['premium_beat_mini'] = array(
    'path' => $players_dir . "/LWMusicPlayer.swf",
    'name' => 'Premium Beat Mini Player',
    //'download_link' => 'http://www.premiumbeat.com/flash_music_players/original/mini/',
    'filetypes' => array('mp3'),
    'callback' => 'audiofield_premium_beat_mini',
  );

	$players['flowplayer'] = array(
      'name' => 'Flowplayer',
      'download_link' => 'http://drupal.org/project/flowplayer',
      'filetypes' => array('mp3'),
      'callback' => 'audiofield_flowplayer',
      'module' => 'flowplayer',
    );


    $players['soundmanager2_360'] = array(
      'path' => $players_dir . "/soundmanager2",
      'name' => 'SoundManager2 360',
      'download_link' => 'http://www.schillmania.com/projects/soundmanager2/',
      'filetypes' => array('mp3', 'mp4', 'aac', 'ogg', 'flac', 'wav'),
      'callback' => 'audiofield_soundmanager2_360',
    );

    $players['soundmanager2_barui'] = array(
      'path' => $players_dir . "/soundmanager2",
      'name' => 'SoundManager2 BarUI',
      'download_link' => 'http://www.schillmania.com/projects/soundmanager2/',
      'filetypes' => array('mp3', 'mp4', 'aac', 'ogg', 'flac', 'wav'),
      'callback' => 'audiofield_soundmanager2_barui',
    );

    $players['soundmanager2_button'] = array(
      'path' => $players_dir . "/soundmanager2",
      'name' => 'SoundManager2 Button',
      'download_link' => 'http://www.schillmania.com/projects/soundmanager2/',
      'filetypes' => array('mp3', 'mp4', 'aac', 'ogg', 'flac', 'wav'),
      'callback' => 'audiofield_soundmanager2_button',
    );

    $players['soundmanager2_inline'] = array(
      'path' => $players_dir . "/soundmanager2",
      'name' => 'SoundManager2 Inline',
      'download_link' => 'http://www.schillmania.com/projects/soundmanager2/',
      'filetypes' => array('mp3', 'mp4', 'aac', 'ogg', 'flac', 'wav'),
      'callback' => 'audiofield_soundmanager2_inline',
    );

    $players['jplayer'] = array(
      'path' => $players_dir . "/jplayer/jquery.jplayer.min.js",
      'css' => $players_dir . "/jplayer/jplayer.css",
      'name' => 'jPlayer',
      'download_link' => 'https://www.drupal.org/project/jplayer',
      'module' => 'jplayer',
      'filetypes' => array('mp3'),
      'callback' => 'audiofield_jplayer',
    );

  return $players;
}

function _audiofield_theme() {
  return array(
    // Themes for the players.
    'audiofield_players_wpaudioplayer' => array(
      'variables' => array('player_path' => NULL, 'audio_file' => NULL),
    ),
    'audiofield_players_xspf_slim' => array(
      'variables' => array('player_path' => NULL, 'audio_file' => NULL),
    ),
    'audiofield_players_xspf_button' => array(
      'variables' => array('player_path' => NULL, 'audio_file' => NULL),
    ),
    'audiofield_players_premium_beat_single_track' => array(
      'variables' => array('player_path' => NULL, 'audio_file' => NULL),
    ),
    'audiofield_players_premium_beat_thin' => array(
      'variables' => array('player_path' => NULL, 'audio_file' => NULL),
    ),
    'audiofield_players_premium_beat_mini' => array(
      'variables' => array('player_path' => NULL, 'audio_file' => NULL),
    ),
  );
}

/* Audio Callback Functions */

function audiofield_embeddedplayer($audio_file) {
  return '<audio src="' . $audio_file . '" controls><embed height="15" src="' . $audio_file . '" autostart="false"></embed></audio>';
}

function audiofield_html5_audio($player_path, $audio_file) {
  return '<audio src="' . $audio_file . '" controls></audio>';
}

function audiofield_wpaudioplayer($player_path, $audio_file) {
  $variables = array(
    'player_path' => $player_path,
    'audio_file' => $audio_file,
  );
  return theme('audiofield_players_wpaudioplayer', $variables);
}

function theme_audiofield_players_wpaudioplayer($variables) {
  $player_path = $variables['player_path'];
  $audio_file = $variables['audio_file'];
  return '<object class="audioplayer2" height="24" width="290" data="' . $player_path . '" type="application/x-shockwave-flash">
                          <param value="' . $player_path . '" name="movie"/>
                          <param value="playerID=2&amp;bg=0xCDDFF3&amp;leftbg=0x357DCE&amp;lefticon=0xF2F2F2&amp;rightbg=0xF06A51&amp;rightbghover=0xAF2910&amp;righticon=0xF2F2F2&amp;righticonhover=0xFFFFFF&amp;text=0x357DCE&amp;slider=0x357DCE&amp;track=0xFFFFFF&amp;border=0xFFFFFF&amp;loader=0xAF2910&amp;soundFile=' . $audio_file . '" name="FlashVars"/>
                          <param value="high" name="quality"/>
                          <param value="false" name="menu"/>
                          <param value="transparent" name="wmode"/>
                          </object>';
}

function audiofield_xspf_slim($player_path, $audio_file, $options) {
	$song_title = "XSPF Slim Music Player";
	if(!empty($options)) {
		if(!empty($options['items'][0]['filename'])) {
			$song_title = $options['items'][0]['filename'];
		}
	}
  $variables = array(
    'player_path' => $player_path,
    'audio_file' => $audio_file,
    'song_title' => $song_title,
  );
  return theme('audiofield_players_xspf_slim', $variables);
}

function theme_audiofield_players_xspf_slim($variables) {
  $player_path = $variables['player_path'];
  $audio_file = $variables['audio_file'];
  $song_title = $variables['song_title'];
  return '<object type="application/x-shockwave-flash" width="175" height="14"
          data="' . $player_path . '?song_url=' . $audio_file . '&song_title=' . $song_title . '">
          <param name="movie" value="' . $player_path . '?song_url=' . $audio_file . '" />
          <param name="wmode" value="transparent" />
          </object>
          ';
}

function audiofield_xspf_button($player_path, $audio_file) {
  $variables = array(
    'player_path' => $player_path,
    'audio_file' => $audio_file,
  );
  return theme('audiofield_players_xspf_button', $variables);
}

function theme_audiofield_players_xspf_button($variables) {
  $player_path = $variables['player_path'];
  $audio_file = $variables['audio_file'];
  return '<object type="application/x-shockwave-flash" width="17" height="17"
          data="' . $player_path . '?song_url=' . $audio_file . '">
          <param name="movie" value="' . $player_path . '?song_url=' . $audio_file . '" />
          <param name="wmode" value="transparent" />
          </object>';
}

function audiofield_premium_beat_single_track($player_path, $audio_file) {
  $variables = array(
    'player_path' => $player_path,
    'audio_file' => $audio_file,
  );
  return theme('audiofield_players_premium_beat_single_track', $variables);
}

function theme_audiofield_players_premium_beat_single_track($variables) {
  $player_path = $variables['player_path'];
  $audio_file = $variables['audio_file'];
  return '<object><param name="autoplay" value="true" />
          <param name="controller"value="true" />
          <embed src="' . $player_path . '"  width="192" height="80" float="left" wmode="transparent" flashvars="mediaPath=' . $audio_file . '"
		  autostart="true" loop="false"  controller="true" bgcolor="#FF9900" pluginspage="http://www.macromedia.com/go/getflashplayer" >
          </embed></object>';
}

function audiofield_premium_beat_thin($player_path, $audio_file) {
  $variables = array(
    'player_path' => $player_path,
    'audio_file' => $audio_file,
  );
  return theme('audiofield_players_premium_beat_thin', $variables);
}

function theme_audiofield_players_premium_beat_thin($variables) {
  $player_path = $variables['player_path'];
  $audio_file = $variables['audio_file'];
  return '<object><param name="autoplay" value="true" />
        <param name="controller"value="true" />
        <embed src="' . $player_path . '"  width="220" height="21" float="left" wmode="transparent" flashvars="mediaPath=' . $audio_file . '&defaultVolume=100" autostart="true" loop="false"  controller="true" bgcolor="#FF9900" pluginspage="http://www.macromedia.com/go/getflashplayer" >
        </embed></object>';
}

function audiofield_premium_beat_mini($player_path, $audio_file) {
  $variables = array(
    'player_path' => $player_path,
    'audio_file' => $audio_file,
  );
  return theme('audiofield_players_premium_beat_mini', $variables);
}

function theme_audiofield_players_premium_beat_mini($variables) {
  $player_path = $variables['player_path'];
  $audio_file = $variables['audio_file'];
  return '<object><param name="autoplay" value="true" />
        <param name="controller"value="true" />
        <embed src="' . $player_path . '"  width="65" height="21" float="left" wmode="transparent" flashvars="mediaPath=' . $audio_file . '&defaultVolume=100" autostart="true" loop="false"  controller="true" bgcolor="#FF9900" pluginspage="http://www.macromedia.com/go/getflashplayer" >
        </embed></object>';
}

function audiofield_soundmanager2_360($player_path, $audio_file) {
  static $instanceIndex = 0;
  if ($audio_file == '') {
    return t('HTML5 media player for soundmanager2 (skin 360-player)');
  }
  else {
    $instanceIndex += 1;
    $player_base_path = config_get('audiofield.settings', 'players_dir') . "/soundmanager2";
    $ie_js = array(
      '#type' => 'markup',
      '#markup' => '<!--[if IE]><script type="text/javascript" src="' . $player_path . '/demo/360-player/script/excanvas.js"></script><![endif]-->',
    );
    backdrop_add_html_head($ie_js, 'audiofield');

    backdrop_add_js($player_base_path . '/script/soundmanager2.js', array('weight' => 0));

    //360 viewer
    backdrop_add_js($player_base_path . '/demo/360-player/script/berniecode-animator.js', array('weight' => 1));
    backdrop_add_js($player_base_path . '/demo/360-player/script/360player.js', array('weight' => 1));
    backdrop_add_css($player_base_path . '/demo/360-player/360player.css');

    return '
    	<div id="sm2-container-real" class="ui360">
		<a href="' . $audio_file . '"></a>
    	</div>
    <script type="text/javascript">

    soundManager.url = "' . $player_path . '/swf"; // directory where SM2 .SWFs live
    soundManager.useFastPolling = true; // increased JS callback frequency, combined with useHighPerformance = true
    soundManager.waitForWindowLoad = true;

    //so Firefox and others without MP3 support work
    soundManager.preferFlash = true;

    // disable debug mode after development/testing..
    //soundManager.debugMode = true;
    soundManager.onready(function () {
      soundManager.stopAll();
      threeSixtyPlayer.init();
    });
    </script>';
  }
}

function audiofield_soundmanager2_barui($player_path, $audio_file) {
  static $instanceIndex = 0;
  if ($audio_file == '') {
    return t('HTML5 media player for soundmanager2 (skin BarUI-player)');
  }
  else {
    $instanceIndex += 1;
    $player_base_path = config_get('audiofield.settings', 'players_dir') . "/soundmanager2";
    $ie_js = array(
      '#type' => 'markup',
      '#markup' => '<!--[if IE]><script type="text/javascript" src="' . $player_path . '/demo/360-player/script/excanvas.js"></script><![endif]-->',
    );
    backdrop_add_html_head($ie_js, 'audiofield');

    backdrop_add_js($player_base_path . '/script/soundmanager2.js', array('weight' => 0));

    //barui viewer
    backdrop_add_js($player_base_path . '/demo/bar-ui/script/bar-ui.js', array('weight' => 1));
    backdrop_add_css($player_base_path . '/demo/bar-ui/css/bar-ui.css');

    return '
    <div class="sm2-bar-ui">
      <div class="bd sm2-main-controls">
        <div class="sm2-inline-texture"></div>
        <div class="sm2-inline-gradient"></div>
        <div class="sm2-inline-element sm2-button-element">
          <div class="sm2-button-bd">
            <a href="#play" class="sm2-inline-button sm2-icon-play-pause">Play / pause</a>
          </div>
        </div>
        <div class="sm2-inline-element sm2-inline-status">
          <div class="sm2-playlist">
            <div class="sm2-playlist-target"><noscript><p>JavaScript is required.</p></noscript></div>
          </div>
          <div class="sm2-progress">
            <div class="sm2-row">
              <div class="sm2-inline-time">0:00</div>
              <div class="sm2-progress-bd">
                <div class="sm2-progress-track">
                  <div class="sm2-progress-bar"></div>
                  <div class="sm2-progress-ball"><div class="icon-overlay"></div></div>
                </div>
              </div>
              <div class="sm2-inline-duration">0:00</div>
            </div>
          </div>
        </div>
        <div class="sm2-inline-element sm2-button-element sm2-volume">
          <div class="sm2-button-bd">
            <span class="sm2-inline-button sm2-volume-control volume-shade"></span>
            <a href="#volume" class="sm2-inline-button sm2-volume-control">volume</a>
          </div>
        </div>
        <div class="sm2-inline-element sm2-button-element sm2-menu">
          <div class="sm2-button-bd">
            <a href="#menu" class="sm2-inline-button sm2-icon-menu">menu</a>
          </div>
        </div>
      </div>
      <div class="bd sm2-playlist-drawer sm2-element">
        <div class="sm2-playlist-wrapper">
          <ul class="sm2-playlist-bd">
              <li>
                <a href="' . $audio_file . '">' . basename($audio_file) . '</a>
              </li>
          </ul>
        </div>
        <div class="sm2-extra-controls">
          <div class="bd">
            <div class="sm2-inline-element sm2-button-element">
              <a href="#prev" title="Previous" class="sm2-inline-button previous">&lt; previous</a>
            </div>
            <div class="sm2-inline-element sm2-button-element">
              <a href="#next" title="Next" class="sm2-inline-button next">&gt; next</a>
            </div>
          </div>
        </div>
      </div>
    </div>';
  }
}

function audiofield_soundmanager2_button($player_path, $audio_file) {
  static $instanceIndex = 0;
  if ($audio_file == '') {
    return t('HTML5 media player for soundmanager2 (skin Button-player)');
  }
  else {
    $instanceIndex += 1;
    $player_base_path = config_get('audiofield.settings', 'players_dir') . "/soundmanager2";
    $ie_js = array(
      '#type' => 'markup',
      '#markup' => '<!--[if IE]><script type="text/javascript" src="' . $player_path . '/demo/360-player/script/excanvas.js"></script><![endif]-->',
    );
    backdrop_add_html_head($ie_js, 'audiofield');

    backdrop_add_js($player_base_path . '/script/soundmanager2.js', array('weight' => 0));

    //mp3 player button viewer
    backdrop_add_js($player_base_path . '/demo/mp3-player-button/script/mp3-player-button.js', array('weight' => 1));
    backdrop_add_css($player_base_path . '/demo/mp3-player-button/css/mp3-player-button.css');

    return '
    	<div id="sm2-container-real" class="sm2-button">
		<a href="' . $audio_file . '">' . basename($audio_file) . '</a>
    	</div>';
  }
}

function audiofield_soundmanager2_inline($player_path, $audio_file) {
  static $instanceIndex = 0;
  if ($audio_file == '') {
    return t('HTML5 media player for soundmanager2 (skin Inline-player)');
  }
  else {
    $instanceIndex += 1;
    $player_base_path = config_get('audiofield.settings', 'players_dir') . "/soundmanager2";
    $ie_js = array(
      '#type' => 'markup',
      '#markup' => '<!--[if IE]><script type="text/javascript" src="' . $player_path . '/demo/360-player/script/excanvas.js"></script><![endif]-->',
    );
    backdrop_add_html_head($ie_js, 'audiofield');

    backdrop_add_js($player_base_path . '/script/soundmanager2.js', array('weight' => 0));

    //mp3 player button viewer
    backdrop_add_js($player_base_path . '/demo/play-mp3-links/script/inlineplayer.js', array('weight' => 1));
    backdrop_add_css($player_base_path . '/demo/play-mp3-links/css/inlineplayer.css');

    return '
    	<ul class="graphic">
		<li><a href="' . $audio_file . '">' . str_replace("_", " ", basename($audio_file)) . '</a></li>
    	</ul>';
  }
}

if (module_exists('flowplayer')) {
  function audiofield_flowplayer($player_path, $audio_file) {
    static $seq = 1;
    $variables = array(
      'config' => array(
        'clip' => array(
          'url' => $audio_file,
          'autoPlay' => FALSE,
        ),
      ),
      'id' => 'audiofield-' . $seq++,
      'attributes' => array('style' => 'height: 24px'),
    );
    return theme('flowplayer', $variables);
  }
}

function audiofield_jplayer($player_path, $audio_file, $options) {
  return theme(
    'jplayer',
    array(
      'entity_type' => $options['entity_type'],
      'entity' => $options['entity'],
      'field_name' => $options['instance']['field_name'],
      'items' => $options['items'],
      'settings' => array(
    'autoplay' => 0,
    'solution' => 'html, flash',
    'preload' => 'metadata',
    'volume' => 80,
    'muted' => FALSE,
    'repeat' => 'none',
    'backgroundColor' => '000000',
    'mode' => 'playlist',
  ),
    )
  );
}
