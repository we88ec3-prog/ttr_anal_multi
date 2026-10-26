
undefined4 * FUN_007b71b0(undefined4 *param_1,int param_2)

{
  int in_EAX;
  undefined4 *puVar1;
  bool bVar2;
  
  puVar1 = *(undefined4 **)(*(int *)(in_EAX + 4) + 4);
  bVar2 = true;
  if (*(char *)((int)puVar1 + 0x15) == '\0') {
    do {
      bVar2 = *(uint *)(param_2 + 0xc) < (uint)puVar1[3];
      if (bVar2) {
        puVar1 = (undefined4 *)*puVar1;
      }
      else {
        puVar1 = (undefined4 *)puVar1[2];
      }
    } while (*(char *)((int)puVar1 + 0x15) == '\0');
  }
  puVar1 = (undefined4 *)FUN_0044bd00(&param_2,bVar2,param_2);
  *param_1 = *puVar1;
  *(undefined1 *)(param_1 + 1) = 1;
  return param_1;
}

