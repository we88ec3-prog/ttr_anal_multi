
undefined4 * FUN_004858c0(undefined4 *param_1,int *param_2)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  bool bVar4;
  
  puVar3 = *(undefined4 **)(in_EAX + 4);
  bVar4 = true;
  if (*(char *)((int)puVar3[1] + 0x11) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      puVar3 = puVar1;
      bVar4 = *param_2 < (int)puVar3[3];
      if (bVar4) {
        puVar1 = (undefined4 *)*puVar3;
      }
      else {
        puVar1 = (undefined4 *)puVar3[2];
      }
    } while (*(char *)((int)puVar1 + 0x11) == '\0');
  }
  if (bVar4) {
    if (puVar3 == (undefined4 *)**(int **)(in_EAX + 4)) {
      uVar2 = FUN_006bde40(param_2);
      bVar4 = true;
      goto LAB_0048591a;
    }
    FUN_007a3230();
  }
  if (*param_2 <= (int)puVar3[3]) {
    *param_1 = puVar3;
    *(undefined1 *)(param_1 + 1) = 0;
    return param_1;
  }
  uVar2 = FUN_006bde40(param_2);
LAB_0048591a:
  FUN_00853180(&param_2,bVar4,uVar2);
  *param_1 = param_2;
  *(undefined1 *)(param_1 + 1) = 1;
  return param_1;
}

