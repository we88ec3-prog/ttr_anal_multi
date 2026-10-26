
void FUN_00732640(undefined4 param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  undefined **ppuVar2;
  code *pcVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  undefined **in_ECX;
  undefined **ppuVar12;
  undefined **local_40;
  int local_3c;
  int *local_38;
  undefined4 local_34;
  char ***local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f3a8;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = param_2;
  local_34 = param_3;
  local_40 = in_ECX;
  local_14 = uVar4;
  pcVar5 = (char *)FUN_00731170(param_3,uVar4);
  for (ppuVar2 = in_ECX; ppuVar2 != (undefined **)0x0; ppuVar2 = (undefined **)ppuVar2[4]) {
    iVar6 = (**(code **)(*ppuVar2 + 0x10))();
    if (iVar6 != 0) {
      local_3c = (**(code **)(*ppuVar2 + 0x10))();
      goto LAB_007326b1;
    }
  }
  local_3c = 0;
LAB_007326b1:
  piVar10 = local_38;
  iVar6 = local_3c;
  if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) {
    if ((local_3c != 0) && (*(char *)(local_3c + 0x44) == '\0')) {
      *(undefined1 *)(local_3c + 0x44) = 1;
      *(undefined4 *)(local_3c + 0x48) = 4;
      pcVar5 = PTR_s_Error_parsing_Element__00d63c98;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(PTR_s_Error_parsing_Element__00d63c98,
                   (int)pcVar5 - (int)(PTR_s_Error_parsing_Element__00d63c98 + 1));
      *(undefined4 *)(iVar6 + 0x70) = 0xffffffff;
      *(undefined4 *)(iVar6 + 0x6c) = 0xffffffff;
      local_40 = TiXmlErrorReporter::vftable;
      FUN_00731de0(&local_40,0,0,local_34);
    }
  }
  else {
    if (local_38 != (int *)0x0) {
      FUN_00730f80(pcVar5,local_34);
      in_ECX[1] = (undefined *)*piVar10;
      in_ECX[2] = (undefined *)piVar10[1];
    }
    if (*pcVar5 == '<') {
      uVar7 = FUN_00731170(local_34,uVar4);
      pcVar5 = (char *)FUN_007312f0(in_ECX + 8);
      if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) {
        if (iVar6 != 0) {
          FUN_00732010(5,uVar7,local_38,local_34);
        }
      }
      else {
        FUN_00402b70(&DAT_00c44d10);
        local_8 = 0;
        FUN_00401ed0(in_ECX + 8,0,0xffffffff);
        FUN_004020e0(local_30);
        while (*pcVar5 != '\0') {
          pcVar8 = (char *)FUN_00731170(local_34);
          piVar10 = local_38;
          if ((pcVar8 == (char *)0x0) || (cVar1 = *pcVar8, cVar1 == '\0')) {
            if (iVar6 != 0) {
              FUN_00732010(7,pcVar5,local_38,local_34);
            }
            FUN_00402c50();
            goto LAB_00732a29;
          }
          if (cVar1 == '/') {
            if (pcVar8[1] == '>') {
              FUN_00402c50();
            }
            else {
              if (iVar6 != 0) {
                FUN_00732010(8,pcVar8 + 1,local_38,local_34);
              }
LAB_00732852:
              FUN_00402c50();
            }
            goto LAB_00732a29;
          }
          if (cVar1 == '>') {
            pcVar5 = (char *)FUN_00732a50(local_40,pcVar8 + 1,local_38,local_34);
            if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) goto LAB_00732852;
            if (local_1c < 0x10) {
              local_30[0] = (char ***)local_30;
            }
            iVar9 = (int)pcVar5 - (int)local_30[0];
            goto LAB_007328a0;
          }
          iVar9 = FUN_00891268(0x54);
          if ((iVar9 == 0) ||
             (piVar10 = (int *)FUN_0072d9b0(), iVar6 = local_3c, piVar10 == (int *)0x0)) {
            if (iVar6 != 0) {
              FUN_00732010(3,pcVar5,local_38,local_34);
            }
            FUN_00402c50();
            goto LAB_00732a29;
          }
          pcVar3 = *(code **)(*piVar10 + 8);
          piVar10[4] = local_3c;
          pcVar5 = (char *)(*pcVar3)(pcVar8,local_38,local_34);
          ppuVar2 = local_40;
          if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) {
            if (local_3c != 0) {
              FUN_00732010(4,pcVar8,local_38,local_34);
            }
            (**(code **)*piVar10)(1);
            FUN_00402c50();
            goto LAB_00732a29;
          }
          piVar11 = piVar10 + 5;
          if (0xf < (uint)piVar10[10]) {
            piVar11 = (int *)*piVar11;
          }
          ppuVar12 = local_40 + 0x11;
          iVar6 = FUN_007300a0(piVar11);
          if (iVar6 != 0) {
            FUN_0072db50(iVar6);
            (**(code **)*piVar10)(1);
            FUN_00402c50();
            goto LAB_00732a29;
          }
          piVar10[0x14] = (int)ppuVar12;
          piVar10[0x13] = (int)ppuVar2[0x24];
          *(int **)(ppuVar2[0x24] + 0x50) = piVar10;
          ppuVar2[0x24] = (undefined *)piVar10;
          iVar6 = local_3c;
        }
        FUN_00402c50();
      }
    }
    else if (iVar6 != 0) {
      FUN_00732010(4,pcVar5,local_38,local_34);
    }
  }
  goto LAB_00732a29;
  while ((*(char *)((int)local_30[0] + iVar9) == *(char *)local_30[0] &&
         (local_30[0] = (char ***)((int)local_30[0] + 1),
         *(char *)((int)local_30[0] + iVar9) != '\0'))) {
LAB_007328a0:
    if (*(char *)local_30[0] == '\0') goto LAB_007328b7;
  }
  if (*(char *)local_30[0] == '\0') {
LAB_007328b7:
    FUN_00402c50();
  }
  else {
    if (iVar6 != 0) {
      FUN_00732010(9,pcVar5,piVar10,local_34);
    }
    FUN_00402c50();
  }
LAB_00732a29:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

