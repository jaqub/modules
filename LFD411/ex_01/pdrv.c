#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/of.h>

#define DRV_NAME "sample_driver"

static struct of_device_id device_id[] = {
  {
    .compatible="fake,dummy",
  },
  {},
};

static int pdrv_probe(struct platform_device *pdev) {
  pr_info("pdrv_probe called\n");
  return 0;
}

static int pdrv_remove(struct platform_device *pdev) {
  pr_info("pdrv_remove called\n");
  return 0;
}

static struct platform_driver sample_driver = {
  .driver = {
    .name = DRV_NAME,
    .owner = THIS_MODULE,
    .of_match_table = device_id,
  },
  .probe = pdrv_probe,
  .remove = pdrv_remove,
};

static int __init drv_init(void) {
  pr_info("Platform driver initializationi: %s\n", DRV_NAME);
  return platform_driver_register(&sample_driver);
}

static void __exit drv_exit(void) {
  pr_info("Unloading platform driver\n");
  platform_driver_unregister(&sample_driver);
}

module_init(drv_init);
module_exit(drv_exit);

MODULE_AUTHOR("Jakub Biwel");
MODULE_DESCRIPTION("Sample driver");
MODULE_LICENSE("GPL v2");
