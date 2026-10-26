
void FUN_008675d0(undefined4 *param_1)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  
  if (*(int *)(in_EAX + 8) == 0) {
    puVar1 = (undefined4 *)FUN_00891268(0x44);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      _memset(puVar1,0,0x44);
      puVar1[0xf] = 0x3f800000;
      puVar1[10] = 0x3f800000;
      puVar1[5] = 0x3f800000;
      *puVar1 = 0x3f800000;
    }
    *(undefined4 **)(in_EAX + 8) = puVar1;
  }
  puVar1 = *(undefined4 **)(in_EAX + 8);
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_1;
    param_1 = param_1 + 1;
    puVar1 = puVar1 + 1;
  }
  return;
}

