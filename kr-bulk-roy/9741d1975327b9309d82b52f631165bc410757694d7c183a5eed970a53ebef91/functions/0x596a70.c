
void FUN_00596a70(void)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 **ppuVar6;
  int *piVar7;
  int in_ECX;
  undefined4 *puVar8;
  int *local_28;
  undefined4 local_24;
  int *local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009167f8;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_005358c0(&local_28,in_ECX + 100);
  local_8 = 0;
  piVar7 = (int *)*local_28;
  local_1c = local_28;
  if (piVar7 != local_28) {
    do {
      puVar8 = (undefined4 *)(*(undefined4 **)(in_ECX + 0xa4))[1];
      uVar2 = ((int *)piVar7[2])[8];
      cVar1 = *(char *)((int)puVar8 + 0x11);
      local_14 = *(undefined4 **)(in_ECX + 0xa4);
      while (cVar1 == '\0') {
        if ((uint)puVar8[3] < uVar2) {
          puVar5 = (undefined4 *)puVar8[2];
          puVar8 = local_14;
        }
        else {
          puVar5 = (undefined4 *)*puVar8;
        }
        local_14 = puVar8;
        puVar8 = puVar5;
        cVar1 = *(char *)((int)puVar5 + 0x11);
      }
      if ((local_14 == *(undefined4 **)(in_ECX + 0xa4)) || (uVar2 < (uint)local_14[3])) {
        local_18 = *(undefined4 **)(in_ECX + 0xa4);
        ppuVar6 = &local_18;
      }
      else {
        ppuVar6 = &local_14;
      }
      if (*ppuVar6 != *(undefined4 **)(in_ECX + 0xa4)) {
        (**(code **)(*(int *)piVar7[2] + 0x94))(1,uVar4);
      }
      piVar7 = (int *)*piVar7;
    } while (piVar7 != local_1c);
  }
  FUN_00851420();
  piVar7 = (int *)*local_28;
  *local_28 = (int)local_28;
  local_28[1] = (int)local_28;
  local_24 = 0;
  if (piVar7 != local_28) {
    do {
      piVar3 = (int *)*piVar7;
      FUN_0089120c(piVar7);
      piVar7 = piVar3;
    } while (piVar3 != local_28);
  }
  FUN_0089120c(local_28);
  ExceptionList = local_10;
  return;
}

