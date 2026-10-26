
void FUN_006fb170(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int local_c;
  undefined4 *local_8;
  
  iVar1 = *(int *)(param_1 + 0x10);
  FUN_006fb130();
  FUN_006fa890(iVar1);
  *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar1 + 0x2c);
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  if ((*(byte *)(param_1 + 5) & 3) != 0) {
    FUN_006f9f70(iVar1,param_1);
  }
  FUN_006fafd0();
  FUN_006fa890(iVar1);
  *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar1 + 0x28);
  *(undefined4 *)(iVar1 + 0x28) = 0;
  FUN_006fa890(iVar1);
  iVar4 = *(int *)(param_1 + 0x10);
  local_c = 0;
  puVar2 = *(undefined4 **)(iVar4 + 0x70);
  for (local_8 = (undefined4 *)**(undefined4 **)(iVar4 + 0x70); local_8 != (undefined4 *)0x0;
      local_8 = (undefined4 *)*local_8) {
    if (((*(byte *)((int)local_8 + 5) & 3) != 0) && ((*(byte *)((int)local_8 + 5) & 8) == 0)) {
      if ((local_8[2] == 0) ||
         (((*(byte *)(local_8[2] + 6) & 4) != 0 || (iVar3 = FUN_006fea60(2), iVar3 == 0)))) {
        *(byte *)((int)local_8 + 5) = *(byte *)((int)local_8 + 5) | 8;
      }
      else {
        *(byte *)((int)local_8 + 5) = *(byte *)((int)local_8 + 5) | 8;
        local_c = local_c + 0x18 + local_8[4];
        *puVar2 = *local_8;
        if (*(undefined4 **)(iVar4 + 0x30) == (undefined4 *)0x0) {
          *local_8 = local_8;
        }
        else {
          *local_8 = **(undefined4 **)(iVar4 + 0x30);
          **(undefined4 **)(iVar4 + 0x30) = local_8;
        }
        *(undefined4 **)(iVar4 + 0x30) = local_8;
        local_8 = puVar2;
      }
    }
    puVar2 = local_8;
  }
  FUN_006fa050();
  iVar4 = FUN_006fa890(iVar1);
  FUN_006fa9c0(*(undefined4 *)(iVar1 + 0x2c));
  *(byte *)(iVar1 + 0x14) = *(byte *)(iVar1 + 0x14) ^ 3;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(int *)(iVar1 + 0x20) = iVar1 + 0x1c;
  *(undefined1 *)(iVar1 + 0x15) = 2;
  *(int *)(iVar1 + 0x48) = *(int *)(iVar1 + 0x44) - (iVar4 + local_c);
  return;
}

