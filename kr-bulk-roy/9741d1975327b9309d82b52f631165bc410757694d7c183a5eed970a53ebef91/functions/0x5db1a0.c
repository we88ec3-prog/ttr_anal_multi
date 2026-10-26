
uint FUN_005db1a0(int *param_1)

{
  uint in_EAX;
  
  if (param_1[1] != 0) {
    if (*param_1 == 100) {
      in_EAX = (**(code **)(*(int *)param_1[1] + 8))();
      if (in_EAX == 0xf4245) {
        in_EAX = *(uint *)(param_1[1] + 0x260);
        if (((in_EAX == 5) || (in_EAX == 0xd)) || (in_EAX == 0x1a)) {
          return CONCAT31((int3)(in_EAX >> 8),1);
        }
        goto LAB_005db1f7;
      }
    }
    if ((param_1[1] != 0) && (*param_1 == 100)) {
      in_EAX = (**(code **)(*(int *)param_1[1] + 8))();
    }
  }
LAB_005db1f7:
  return in_EAX & 0xffffff00;
}

