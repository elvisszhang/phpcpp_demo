<?php
$counter = new Counter;
echo 'result of increment() = '. $counter->increment() . PHP_EOL;
echo 'result of increment() = '. $counter->increment() . PHP_EOL;
echo 'result of decrement() = '. $counter->decrement() . PHP_EOL;
echo 'result of value() = '. $counter->value() . PHP_EOL;
echo 'result of gettime() = '. Counter::gettime() . PHP_EOL;
?>