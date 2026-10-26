
void FUN_007742f0(char *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  int *piVar6;
  int in_ECX;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  char *local_38;
  uint local_34;
  uint local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915538;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = param_1;
  local_40 = in_ECX;
  iVar3 = FUN_0077dd40(local_14);
  if (iVar3 == 0) {
    iVar3 = *(int *)(in_ECX + 0x268);
    local_34 = 0;
    if (*(int *)(in_ECX + 0x26c) - iVar3 >> 2 != 0) {
      do {
        iVar3 = *(int *)(iVar3 + local_34 * 4);
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = local_30[0] & 0xffffff00;
        pcVar4 = param_1;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        local_44 = iVar3;
        FUN_00402a70(param_1,(int)pcVar4 - (int)(param_1 + 1));
        local_8 = 0;
        local_48 = FUN_007b6f30(local_30);
        iVar3 = *(int *)(iVar3 + 0x210);
        if (local_48 == iVar3) {
LAB_00774401:
          local_3c = iVar3;
          piVar6 = &local_3c;
        }
        else {
          uVar2 = *(uint *)(local_48 + 0x1c);
          uVar5 = local_20;
          if (uVar2 <= local_20) {
            uVar5 = uVar2;
          }
          uVar5 = FUN_00407e70(uVar5);
          if (uVar5 == 0) {
            if (local_20 < uVar2) {
              uVar5 = 0xffffffff;
            }
            else {
              uVar5 = (uint)(local_20 != uVar2);
            }
          }
          param_1 = local_38;
          if ((int)uVar5 < 0) goto LAB_00774401;
          piVar6 = &local_48;
        }
        iVar3 = *piVar6;
        local_8 = 0xffffffff;
        if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = local_30[0] & 0xffffff00;
        if ((iVar3 != *(int *)(local_44 + 0x210)) && (*(int *)(iVar3 + 0x28) != 0)) break;
        iVar3 = *(int *)(local_40 + 0x268);
        local_34 = local_34 + 1;
      } while (local_34 < (uint)(*(int *)(local_40 + 0x26c) - iVar3 >> 2));
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

