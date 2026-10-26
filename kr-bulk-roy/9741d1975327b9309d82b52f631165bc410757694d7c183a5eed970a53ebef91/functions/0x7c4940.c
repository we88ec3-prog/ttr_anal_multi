
void FUN_007c4940(void)

{
  char cVar1;
  uint uVar2;
  char ****ppppcVar3;
  int in_ECX;
  char ****ppppcVar4;
  int iVar5;
  int local_5c;
  int local_58;
  char ***local_54 [4];
  undefined4 local_44;
  uint local_40;
  uint local_38 [4];
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00937c8e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_5c;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
  if (*(char *)(in_ECX + 0x60) != '\0') {
    local_58 = *(int *)(in_ECX + 0x78);
    iVar5 = *(int *)(in_ECX + 0x74);
    local_5c = in_ECX;
    if (iVar5 != local_58) {
      do {
        local_40 = 0xf;
        local_44 = 0;
        local_54[0] = (char ***)((uint)local_54[0] & 0xffffff00);
        FUN_00403040(iVar5,0,0xffffffff);
        local_c = 0;
        FUN_007c5600(local_38);
        local_c._0_1_ = 1;
        ppppcVar4 = (char ****)local_54[0];
        if (local_40 < 0x10) {
          ppppcVar4 = local_54;
        }
        ppppcVar3 = ppppcVar4;
        do {
          cVar1 = *(char *)ppppcVar3;
          ppppcVar3 = (char ****)((int)ppppcVar3 + 1);
        } while (cVar1 != '\0');
        FUN_00401fc0(ppppcVar4,(int)ppppcVar3 - (int)((int)ppppcVar4 + 1));
        if ((DAT_00fe1ac0 & 1) == 0) {
          DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
          local_c._0_1_ = 2;
          FUN_007bb970();
          _atexit((_func_4879 *)&LAB_00bceac0);
          local_c._0_1_ = 1;
        }
        FUN_007bcf60();
        if (0xf < local_24) {
          FUN_0089120c(local_38[0]);
        }
        local_c = 0xffffffff;
        local_24 = 0xf;
        local_28 = 0;
        local_38[0] = local_38[0] & 0xffffff00;
        if (0xf < local_40) {
          FUN_0089120c(local_54[0]);
        }
        iVar5 = iVar5 + 0x1c;
        local_40 = 0xf;
        local_44 = 0;
        local_54[0] = (char ***)((uint)local_54[0] & 0xffffff00);
        in_ECX = local_5c;
      } while (iVar5 != local_58);
    }
    FUN_007d6200(uVar2);
    if (*(undefined4 **)(in_ECX + 0xec) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0xec))(1);
      *(undefined4 *)(in_ECX + 0xec) = 0;
    }
    *(undefined1 *)(in_ECX + 0x60) = 0;
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_5c);
  return;
}

