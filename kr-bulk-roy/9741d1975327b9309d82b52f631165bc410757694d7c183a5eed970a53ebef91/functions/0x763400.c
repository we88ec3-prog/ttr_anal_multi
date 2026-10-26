
void FUN_00763400(void)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int unaff_ESI;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_58 [4];
  undefined4 local_54 [5];
  uint local_40;
  undefined1 local_38 [28];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009190ce;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_58;
  ExceptionList = &local_14;
  if ((*(char *)(unaff_ESI + 0x98) == '\0') && (0 < *(int *)(unaff_ESI + 0x9c))) {
    if ((DAT_00fcde40 & 1) == 0) {
      DAT_00fcde40 = DAT_00fcde40 | 1;
      local_c = 0;
      FUN_00736880(DAT_00d61f20 ^ (uint)&stack0xffffffa0);
      _atexit(FUN_00bce6f0);
    }
    local_c = 0xffffffff;
    if (DAT_00fcde2c != 0) {
      piVar3 = (int *)(unaff_ESI + 0x2c);
      piVar1 = piVar3;
      if (7 < *(uint *)(unaff_ESI + 0x40)) {
        piVar1 = (int *)*piVar3;
      }
      FUN_00402250(piVar1);
      puVar4 = local_54;
      local_c = 1;
      FUN_0049b2a0(puVar4);
      uVar2 = FUN_00736c70(puVar4);
      local_c = 0xffffffff;
      *(undefined4 *)(unaff_ESI + 8) = uVar2;
      if (7 < local_40) {
        FUN_0089120c(local_54[0]);
      }
      if (*(int *)(unaff_ESI + 8) == 0) {
        if (7 < *(uint *)(unaff_ESI + 0x40)) {
          piVar3 = (int *)*piVar3;
        }
        FUN_00402250(piVar3);
        puVar5 = local_38;
        local_c = 2;
        FUN_0049b2a0(puVar5);
        uVar2 = FUN_00736b00(puVar5);
        *(undefined4 *)(unaff_ESI + 8) = uVar2;
        local_c = 0xffffffff;
        FUN_004fa440();
      }
      uVar2 = (**(code **)(**(int **)(unaff_ESI + 8) + 0x14))();
      *(undefined4 *)(unaff_ESI + 0x58) = uVar2;
      uVar2 = (**(code **)(**(int **)(unaff_ESI + 8) + 0x18))();
      *(undefined4 *)(unaff_ESI + 0x88) = 0;
      *(undefined4 *)(unaff_ESI + 0x8c) = 0;
      *(undefined4 *)(unaff_ESI + 0x90) = *(undefined4 *)(unaff_ESI + 0x58);
      *(undefined4 *)(unaff_ESI + 0x5c) = uVar2;
      *(undefined4 *)(unaff_ESI + 0x94) = uVar2;
      *(undefined1 *)(unaff_ESI + 0x98) = 1;
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_58);
  return;
}

