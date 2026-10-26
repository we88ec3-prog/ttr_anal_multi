
/* WARNING: Removing unreachable block (ram,0x004d9e16) */
/* WARNING: Removing unreachable block (ram,0x004d9e3b) */

void FUN_004d9d20(int param_1,ushort param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int *in_ECX;
  int *piVar6;
  int local_60;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009107b8;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar6 = (int *)**(int **)(param_1 + 4);
  if (piVar6 != *(int **)(param_1 + 4)) {
    do {
      FUN_004026e0(piVar6 + 4,0,0xffffffff);
      local_8 = 0;
      FUN_004026e0(piVar6 + 0xb,0,0xffffffff);
      iVar2 = piVar6[0x14];
      local_8 = 0xffffffff;
      if (((*(byte *)(piVar6 + 0x12) == param_2) &&
          (FUN_004a4cc0(piVar6 + 3), local_60 != *(int *)(param_1 + 0x14))) &&
         (*(int *)(*(int *)(local_60 + 0x10) + 0xc) != 0)) {
        *in_ECX = iVar2;
        FUN_005375f0();
        break;
      }
      if (*(char *)((int)piVar6 + 0x55) == '\0') {
        piVar3 = (int *)piVar6[2];
        if (*(char *)((int)piVar3 + 0x55) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x55);
          piVar6 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x55);
            piVar6 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x55);
          piVar4 = (int *)piVar6[1];
          piVar3 = piVar6;
          while ((piVar6 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar6[2]))) {
            cVar1 = *(char *)(piVar6[1] + 0x55);
            piVar4 = (int *)piVar6[1];
            piVar3 = piVar6;
          }
        }
      }
    } while (piVar6 != *(int **)(param_1 + 4));
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar5 ^ (uint)&stack0xfffffffc);
  return;
}

