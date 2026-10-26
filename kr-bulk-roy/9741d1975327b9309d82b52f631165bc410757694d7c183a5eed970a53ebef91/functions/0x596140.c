
undefined4 FUN_00596140(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  int in_EAX;
  code *pcVar4;
  int local_c;
  
  FUN_0082ef00(&stack0xfffffff8);
  if (local_c != *(int *)(in_EAX + 0x84)) {
    puVar1 = *(undefined4 **)(*(int *)(local_c + 0x10) + 4);
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      if (param_1 == 1) {
        pcVar4 = *(code **)(*(int *)puVar2[2] + 0xec);
LAB_0059619b:
        cVar3 = (*pcVar4)();
        if (cVar3 != '\0') {
          return 1;
        }
      }
      else if (param_1 == 3) {
        pcVar4 = *(code **)(*(int *)puVar2[2] + 0xf0);
        goto LAB_0059619b;
      }
    }
  }
  return 0;
}

