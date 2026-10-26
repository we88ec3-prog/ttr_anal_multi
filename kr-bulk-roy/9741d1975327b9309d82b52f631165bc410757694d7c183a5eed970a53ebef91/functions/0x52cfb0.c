
ushort * FUN_0052cfb0(char *param_1,ushort *param_2)

{
  char *pcVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort local_40 [2];
  undefined1 local_3c [4];
  undefined4 *local_38;
  undefined4 *local_28;
  undefined4 local_24;
  undefined **local_1c [3];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pcVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910092;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar4 = *(ushort **)(param_1 + 4);
  if (*(char *)((int)*(ushort **)(puVar4 + 2) + 0x21) == '\0') {
    puVar2 = *(ushort **)(puVar4 + 2);
    do {
      if (puVar2[6] < *param_2) {
        puVar3 = *(ushort **)(puVar2 + 4);
      }
      else {
        puVar3 = *(ushort **)puVar2;
        puVar4 = puVar2;
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar3 + 0x21) == '\0');
  }
  if ((puVar4 == *(ushort **)(param_1 + 4)) || (*param_2 < puVar4[6])) {
    local_24 = 0;
    local_28 = (undefined4 *)FUN_00891268(0x30,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (local_28 == (undefined4 *)0x0) {
      param_1 = (char *)0x0;
      std::exception::exception((exception *)local_1c,&param_1);
      local_1c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_1c,&DAT_00c857a8);
    }
    *local_28 = local_28;
    local_28[1] = local_28;
    local_28[2] = local_28;
    *(undefined1 *)(local_28 + 10) = 1;
    *(undefined1 *)((int)local_28 + 0x29) = 1;
    local_8 = 0;
    local_40[0] = *param_2;
    FUN_0052dbd0(local_3c);
    local_8._0_1_ = 1;
    FUN_0052ea00(local_40);
    FUN_0052e020(pcVar1,puVar4);
    puVar4 = param_2;
    param_2 = (ushort *)local_3c;
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_0052da40(*local_38,local_38);
    FUN_0089120c(local_38);
    local_8 = 3;
    FUN_0052da40(*local_28,local_28);
    FUN_0089120c(local_28);
  }
  ExceptionList = local_10;
  return puVar4 + 8;
}

