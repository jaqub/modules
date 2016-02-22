#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/platform_device.h>

#define DEVICE_NAME "sample_device"

static struct platform_device sample_device = {
  .name = DEVICE_NAME,
  .num_resources = 0,
};

static int __init dev_init(void) {
  return platform_device_register(&sample_device);
}

static void __exit dev_exit(void) {
  platform_device_unregister(&sample_device);
}

module_init(dev_init);
module_exit(dev_exit);

MODULE_AUTHOR("Jakub Biwel");
MODULE_DESCRIPTION("Sample device");
MODULE_LICENSE("GPL v2");
  
