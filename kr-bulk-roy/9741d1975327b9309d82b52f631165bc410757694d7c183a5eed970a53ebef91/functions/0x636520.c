
void FUN_00636520(int param_1,int param_2)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  int *in_EDX;
  undefined1 local_3c [4];
  char *local_38;
  undefined **local_34 [3];
  undefined1 local_28 [4];
  undefined4 *local_24;
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  iVar2 = DAT_00fe1bd0;
  local_c = 0xffffffff;
  puStack_10 = &LAB_00949232;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  in_EDX[0x20] = param_1;
  in_EDX[0x21] = in_ECX;
  FUN_008438c0(local_3c);
  if (local_38 == *(char **)(iVar2 + 0xc)) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(local_38 + 0x10);
  }
  in_EDX[0x2e] = iVar2;
  in_EDX[0x24] = param_2;
  in_EDX[0x22] = 0;
  FUN_006389e0(in_EDX[0x2f],in_ECX);
  local_20 = 0;
  local_24 = (undefined4 *)FUN_00891268(0x24,uVar1);
  if (local_24 == (undefined4 *)0x0) {
    local_38 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_38);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  *local_24 = local_24;
  local_24[1] = local_24;
  local_24[2] = local_24;
  *(undefined1 *)(local_24 + 8) = 1;
  *(undefined1 *)((int)local_24 + 0x21) = 1;
  local_c = 0;
  FUN_004fc250(DAT_00fe1db4,in_EDX[0x20],in_EDX[0x21],local_28,0);
  *(bool *)(in_EDX + 0x23) = local_20 != 0;
  switch(in_EDX[0x24]) {
  case 0:
    (**(code **)(*(int *)in_EDX[0x2f] + 8))();
    (**(code **)(*(int *)in_EDX[0x2f] + 4))();
    FUN_00635ca0();
    goto switchD_00636629_default;
  case 1:
    (**(code **)(*(int *)in_EDX[0x2f] + 8))();
    FUN_0040f930();
    iVar2 = FUN_00500f90();
    in_EDX[0x22] = iVar2;
    if (iVar2 == 0) {
LAB_006366ed:
      (**(code **)(*in_EDX + 0xd4))();
    }
    else {
      FUN_00635f10(*(undefined4 *)(iVar2 + 0x30));
    }
    break;
  case 2:
    (**(code **)(*(int *)in_EDX[0x2f] + 8))();
    FUN_0040f930();
    iVar2 = FUN_00500f90();
    in_EDX[0x22] = iVar2;
    if (iVar2 == 0) goto LAB_006366ed;
    FUN_00635f10(*(undefined4 *)(iVar2 + 0x34));
    break;
  case 3:
    (**(code **)(*(int *)in_EDX[0x2f] + 8))();
    FUN_0040f930();
    iVar2 = FUN_00500f90();
    in_EDX[0x22] = iVar2;
    if (iVar2 == 0) goto LAB_006366ed;
    FUN_00635f10(*(undefined4 *)(iVar2 + 0x38));
    break;
  default:
    goto switchD_00636629_default;
  }
  (**(code **)(*(int *)in_EDX[0x2f] + 4))();
  FUN_00636050(in_EDX);
switchD_00636629_default:
  local_c = 1;
  FUN_0085e680(*local_24,local_24);
  FUN_0089120c(local_24);
  ExceptionList = local_14;
  return;
}

