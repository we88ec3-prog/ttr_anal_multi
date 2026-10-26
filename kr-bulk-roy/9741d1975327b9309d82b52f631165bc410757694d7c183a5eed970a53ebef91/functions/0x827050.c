
byte * FUN_00827050(char *param_1,byte *param_2)

{
  char *pcVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte local_44 [4];
  char local_40 [4];
  undefined4 *local_3c;
  undefined4 *local_2c;
  undefined4 local_28;
  undefined **local_20 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pcVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009095e2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pbVar4 = *(byte **)(param_1 + 4);
  if ((*(byte **)(pbVar4 + 4))[0x21] == 0) {
    pbVar2 = *(byte **)(pbVar4 + 4);
    do {
      if (pbVar2[0xc] < *param_2) {
        pbVar3 = *(byte **)(pbVar2 + 8);
      }
      else {
        pbVar3 = *(byte **)pbVar2;
        pbVar4 = pbVar2;
      }
      pbVar2 = pbVar3;
    } while (pbVar3[0x21] == 0);
  }
  if ((pbVar4 == *(byte **)(param_1 + 4)) || (*param_2 < pbVar4[0xc])) {
    local_28 = 0;
    local_2c = (undefined4 *)FUN_00891268(0x2c,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (local_2c == (undefined4 *)0x0) {
      param_1 = (char *)0x0;
      std::exception::exception((exception *)local_20,&param_1);
      local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_20,&DAT_00c857a8);
    }
    *local_2c = local_2c;
    local_2c[1] = local_2c;
    local_2c[2] = local_2c;
    *(undefined1 *)(local_2c + 10) = 1;
    *(undefined1 *)((int)local_2c + 0x29) = 1;
    local_8 = 0;
    local_44[0] = *param_2;
    FUN_00827290(local_40);
    local_8._0_1_ = 1;
    FUN_00827ba0(local_44);
    FUN_00827370(pcVar1,pbVar4);
    param_1 = local_40;
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00523fe0(*local_3c,local_3c);
    FUN_0089120c(local_3c);
    local_8 = 3;
    FUN_00523fe0(*local_2c,local_2c);
    FUN_0089120c(local_2c);
    pbVar4 = param_2;
  }
  ExceptionList = local_10;
  return pbVar4 + 0x10;
}

