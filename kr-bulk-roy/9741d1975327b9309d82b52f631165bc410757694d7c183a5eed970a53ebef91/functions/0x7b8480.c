
void FUN_007b8480(int param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 ****ppppuVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  char *in_ECX;
  char *in_EDX;
  int local_58;
  undefined4 *local_54;
  undefined1 local_50 [4];
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  undefined4 ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922680;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54 = param_2;
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = local_4c[0] & 0xffffff00;
  pcVar3 = in_EDX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar2;
  FUN_00402a70(in_EDX,(int)pcVar3 - (int)(in_EDX + 1));
  local_8 = 0;
  FUN_007b86f0(&local_58,local_4c);
  local_8 = 0xffffffff;
  if (0xf < local_38) {
    FUN_0089120c(local_4c[0],uVar2);
  }
  if (local_58 != *(int *)(param_1 + 8)) {
    piVar5 = (int *)(*(int *)(local_58 + 0x24) + 0x5c);
    *piVar5 = *piVar5 + 1;
    if (local_54 != (undefined4 *)0x0) {
      *local_54 = *(undefined4 *)(local_58 + 0x24);
    }
    goto LAB_007b8601;
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  local_8 = 1;
  pcVar3 = in_EDX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401fc0(in_EDX,(int)pcVar3 - (int)(in_EDX + 1));
  ppppuVar4 = (undefined4 ****)local_30[0];
  if (local_1c < 0x10) {
    ppppuVar4 = local_30;
  }
  piVar5 = (int *)FUN_00714770(ppppuVar4,&DAT_00bed1e0);
  if (piVar5 != (int *)0x0) {
    iVar6 = FUN_00891268(0x8c);
    if (iVar6 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = FUN_007dcee0();
    }
    (**(code **)(*piVar5 + 0x10))(local_50,1,2);
    (**(code **)(*piVar5 + 0x34))(0,0);
    if ((char)local_50._0_2_ == '<') {
      if (SUB21(local_50._0_2_,1) == '?') {
LAB_007b8628:
        (**(code **)(*piVar5 + 4))();
        FUN_007dd2a0(uVar7);
        FUN_007b82d0(param_1,uVar7);
        if (local_54 != (undefined4 *)0x0) {
          *local_54 = uVar7;
        }
        if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        goto LAB_007b8601;
      }
    }
    else if (((char)local_50._0_2_ == 'E') && (SUB21(local_50._0_2_,1) == 'X')) goto LAB_007b8628;
  }
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
LAB_007b8601:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

