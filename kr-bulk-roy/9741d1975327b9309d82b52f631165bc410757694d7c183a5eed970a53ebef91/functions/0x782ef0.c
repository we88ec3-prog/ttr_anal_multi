
void FUN_00782ef0(int param_1)

{
  uint uVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 ****ppppuVar7;
  size_t sVar8;
  int in_ECX;
  char cVar9;
  size_t _Count;
  char *local_3c;
  int local_38;
  char local_31;
  undefined4 ***local_30;
  undefined4 local_2c;
  undefined1 local_28;
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009284c8;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar5;
  if (param_1 != -1) {
    uVar1 = **(uint **)(in_ECX + 0x24);
    cVar9 = (char)param_1;
    if ((uVar1 == 0) || (piVar2 = *(int **)(in_ECX + 0x34), *piVar2 + uVar1 <= uVar1)) {
      if (*(int *)(in_ECX + 0x54) != 0) {
        if (**(int **)(in_ECX + 0x10) == in_ECX + 0x48) {
          uVar4 = *(undefined4 *)(in_ECX + 0x40);
          **(int **)(in_ECX + 0x10) = *(int *)(in_ECX + 0x3c);
          **(undefined4 **)(in_ECX + 0x20) = uVar4;
          **(undefined4 **)(in_ECX + 0x30) = 0;
        }
        if (*(int *)(in_ECX + 0x44) != 0) {
          local_1c = 0xf;
          local_30 = (undefined4 ****)0x0;
          local_2c = 0;
          local_20 = 8;
          local_28 = 0;
          local_8 = 0;
          local_31 = cVar9;
LAB_00782fd1:
          ppppuVar7 = (undefined4 ****)local_30;
          if (local_1c < 0x10) {
            ppppuVar7 = &local_30;
          }
          iVar6 = (**(code **)(**(int **)(in_ECX + 0x44) + 0x14))
                            (in_ECX + 0x4c,&local_31,&local_30,&local_3c,ppppuVar7,
                             (int)ppppuVar7 + local_20,&local_38,uVar5);
          if (iVar6 < 0) goto LAB_007830b9;
          if (iVar6 < 2) {
            ppppuVar7 = (undefined4 ****)local_30;
            if (local_1c < 0x10) {
              ppppuVar7 = &local_30;
            }
            _Count = local_38 - (int)ppppuVar7;
            if (_Count != 0) {
              ppppuVar7 = (undefined4 ****)local_30;
              if (local_1c < 0x10) {
                ppppuVar7 = &local_30;
              }
              sVar8 = _fwrite(ppppuVar7,1,_Count,*(FILE **)(in_ECX + 0x54));
              if (_Count != sVar8) goto LAB_007830b9;
            }
            *(undefined1 *)(in_ECX + 0x49) = 1;
            if (local_3c == &local_31) goto code_r0x00783052;
            FUN_00402c50();
          }
          else {
            if (iVar6 != 3) goto LAB_007830b9;
            iVar6 = FID_conflict__fputc((int)local_31,*(FILE **)(in_ECX + 0x54));
            if (iVar6 == -1) {
              FUN_00402c50();
            }
            else {
              FUN_00402c50();
            }
          }
          goto LAB_007830c1;
        }
        FID_conflict__fputc((int)cVar9,*(FILE **)(in_ECX + 0x54));
      }
    }
    else {
      *piVar2 = *piVar2 + -1;
      pcVar3 = (char *)**(int **)(in_ECX + 0x24);
      **(int **)(in_ECX + 0x24) = (int)(pcVar3 + 1);
      *pcVar3 = cVar9;
    }
  }
LAB_007830c1:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
code_r0x00783052:
  if (_Count == 0) {
    if (0x1f < local_20) {
LAB_007830b9:
      FUN_00402c50();
      goto LAB_007830c1;
    }
    FUN_00429630(8,0);
  }
  goto LAB_00782fd1;
}

