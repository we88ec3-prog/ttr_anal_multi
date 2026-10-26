
undefined4 * FUN_00463340(undefined4 *param_1,int param_2)

{
  bool bVar1;
  int in_EAX;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(*(int *)(in_EAX + 4) + 4);
  bVar1 = true;
  if (*(char *)((int)puVar2 + 0x25) == '\0') {
    do {
      bVar1 = *(int *)(param_2 + 0xc) < (int)puVar2[3];
      if (bVar1) {
        puVar2 = (undefined4 *)*puVar2;
      }
      else {
        puVar2 = (undefined4 *)puVar2[2];
      }
    } while (*(char *)((int)puVar2 + 0x25) == '\0');
  }
  puVar2 = (undefined4 *)FUN_004633a0(&param_2,bVar1,param_2);
  *param_1 = *puVar2;
  *(undefined1 *)(param_1 + 1) = 1;
  return param_1;
}

