var express = require('express');
var router = express.Router();

/* GET home page. */
router.post('/', function(req, res, next) {
  console.log('post');
  res.render('index', { firstname: req.body.firstname, lastname: req.body.lastname, title: 'Express' });
});

router.get('/', function(req, res, next) {
  console.log('get');
  res.render('index', { title: 'Express' });
});

module.exports = router;
