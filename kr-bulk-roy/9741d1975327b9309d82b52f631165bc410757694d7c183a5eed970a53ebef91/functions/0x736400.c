
undefined4 * FUN_00736400(undefined4 *param_1,int *param_2)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined4 uVar2;
  bool bVar3;
  
  puVar1 = *(undefined4 **)(*(int *)(in_EAX + 4) + 4);
  bVar3 = true;
  if (*(char *)((int)puVar1 + 0x11) == '\0') {
    do {
      bVar3 = *(uint *)(*param_2 + 0x34) < *(uint *)(puVar1[3] + 0x34);
      if (bVar3) {
        puVar1 = (undefined4 *)*puVar1;
      }
      else {
        puVar1 = (undefined4 *)puVar1[2];
      }
    } while (*(char *)((int)puVar1 + 0x11) == '\0');
  }
  uVar2 = FUN_006bde40(param_2);
  FUN_00853180(&param_2,bVar3,uVar2);
  *param_1 = param_2;
  *(undefined1 *)(param_1 + 1) = 1;
  return param_1;
}

