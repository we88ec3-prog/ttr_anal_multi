
int FUN_008e9d60(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 local_20 [8];
  int local_18;
  code *local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_c = *(undefined4 *)(param_2 + 0x1c);
  local_8 = 2;
  iVar2 = FUN_008baee0(local_c,0x2c,&local_8);
  if ((local_8 == 0) && (local_8 = FUN_008babe0(param_2,*(undefined4 *)(param_2 + 4)), local_8 == 0)
     ) {
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(param_1 + 0x1cc);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(param_1 + 0x1d0);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(param_1 + 0x1d4);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(param_1 + 0x1d8);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(param_1 + 0x1d8);
    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(param_1 + 0x1d0);
    iVar1 = *(int *)(param_1 + 0x1e8);
    if ((*(undefined4 **)(iVar1 + 0x18) != (undefined4 *)0x0) &&
       (local_8 = (*(code *)**(undefined4 **)(iVar1 + 0x18))
                            (local_20,*(undefined4 *)(param_2 + 0x1c),
                             *(undefined4 *)(param_2 + 0x20),*(undefined4 *)(param_2 + 0x24)),
       local_8 == 0)) {
      local_14 = FUN_008e9ac0;
      local_18 = iVar2;
      local_10 = param_1 + 0x84;
      local_8 = (**(code **)(*(int *)(iVar1 + 0x18) + 8))(local_20);
      (**(code **)(*(int *)(iVar1 + 0x18) + 4))(local_20);
    }
    if (((((char)local_8 == '\x02') && (6 < *(uint *)(param_2 + 4))) &&
        (*(byte *)(*(int *)(param_2 + 0x20) + 1) < 4)) &&
       (CONCAT31(CONCAT21(*(undefined2 *)(*(int *)(param_2 + 0x20) + 4),
                          *(undefined1 *)(*(int *)(param_2 + 0x20) + 3)),
                 *(undefined1 *)(*(int *)(param_2 + 0x20) + 2)) == *(int *)(param_2 + 4))) {
      local_8 = FUN_008e9b70(iVar2);
    }
    if (local_8 == 0) {
      *(undefined4 *)(param_1 + 0x1cc) = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)(param_1 + 0x1d0) = *(undefined4 *)(iVar2 + 8);
      *(undefined4 *)(param_1 + 0x1d4) = *(undefined4 *)(iVar2 + 0xc);
      *(undefined4 *)(param_1 + 0x1d8) = *(undefined4 *)(iVar2 + 0x10);
      *(int *)(param_1 + 0x34) = (int)*(short *)(iVar2 + 6);
      *(int *)(param_1 + 0x38) = (int)*(short *)(iVar2 + 10);
      *(int *)(param_1 + 0x3c) = *(int *)(iVar2 + 0xc) + 0xffff >> 0x10;
      *(int *)(param_1 + 0x40) = *(int *)(iVar2 + 0x10) + 0xffff >> 0x10;
      *(short *)(param_1 + 0x46) = (short)((uint)(*(int *)(iVar2 + 0x14) + 0x8000) >> 0x10);
      *(short *)(param_1 + 0x48) = (short)((uint)(*(int *)(iVar2 + 0x18) + 0x8000) >> 0x10);
      if (*(int *)(iVar2 + 0x28) != 0) {
        *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x40;
        *(int *)(param_1 + 0x1ec) = iVar2;
        iVar2 = 0;
      }
    }
    FUN_008baca0(param_2);
  }
  if (iVar2 != 0) {
    FUN_008e9a90();
  }
  return local_8;
}

