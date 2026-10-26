
void FUN_0075c2f0(undefined4 param_1,int param_2)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((*(char *)(in_EAX + 0xa4) != '\0') && (*(int *)(in_EAX + 0x24) != 0)) {
    puVar1 = (undefined4 *)FUN_00891268(0x34);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[4] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[5] = 0;
      *puVar1 = FoxUI::FXUIEventI1S1::vftable;
      puVar1[0xb] = 7;
      puVar1[10] = 0;
      *(undefined2 *)(puVar1 + 6) = 0;
    }
    iVar2 = in_EAX;
    if (((*(byte *)(in_EAX + 0x28) & 0x10) == 0) && (iVar2 = 0, *(int *)(in_EAX + 0x60) != 0)) {
      iVar2 = FUN_00745c20();
    }
    puVar1[4] = param_1;
    if (iVar2 == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = *(undefined4 *)(iVar2 + 0x20);
    }
    puVar1[1] = uVar3;
    puVar1[2] = *(undefined4 *)(in_EAX + 0x20);
    puVar1[3] = in_EAX;
    if (*(char *)(param_2 + 0xb0 + in_EAX) == '\0') {
      iVar2 = *(int *)(*(int *)(in_EAX + 0x24) + 0x14c4);
      if (iVar2 == 0) {
        FUN_00402160(&DAT_00bed1fc,0);
        FUN_00750920(puVar1);
        return;
      }
    }
    else {
      iVar2 = in_EAX + 0xa8;
    }
    FUN_0077b6c0(iVar2);
    FUN_00750920(puVar1);
    return;
  }
  return;
}

