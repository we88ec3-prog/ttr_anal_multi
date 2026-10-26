
void FUN_007ea5f0(int param_1)

{
  char cVar1;
  size_t _Size;
  int *piVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  void *_Src;
  void *_Dst;
  int *piVar10;
  int *in_ECX;
  undefined4 ****ppppuVar11;
  double dVar12;
  float local_64;
  float local_60;
  int local_54;
  int local_50 [5];
  undefined4 local_3c;
  uint local_38;
  undefined4 ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914746;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar3;
  if (in_ECX != (int *)0x0) {
    local_54 = 0;
    do {
      iVar4 = (**(code **)(*in_ECX + 0x14))(uVar3);
      if (iVar4 != 0) {
        iVar4 = FUN_007300a0(&DAT_00c50578);
        if (iVar4 == 0) {
          pcVar6 = (char *)0x0;
        }
        else {
          pcVar6 = (char *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            pcVar6 = *(char **)pcVar6;
          }
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
        pcVar5 = pcVar6;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar6,(int)pcVar5 - (int)(pcVar6 + 1));
        local_8 = 0;
        iVar4 = FUN_007300a0("TexWrapX");
        if (iVar4 == 0) {
LAB_007ea6c5:
          local_64 = 0.0;
        }
        else {
          pcVar6 = (char *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            pcVar6 = *(char **)pcVar6;
          }
          if (pcVar6 == (char *)0x0) goto LAB_007ea6c5;
          dVar12 = _atof(pcVar6);
          local_64 = (float)dVar12;
        }
        iVar4 = FUN_007300a0("TexWrapY");
        if (iVar4 == 0) {
LAB_007ea6f4:
          local_60 = 0.0;
        }
        else {
          pcVar6 = (char *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            pcVar6 = *(char **)pcVar6;
          }
          if (pcVar6 == (char *)0x0) goto LAB_007ea6f4;
          dVar12 = _atof(pcVar6);
          local_60 = (float)dVar12;
        }
        iVar4 = FUN_007300a0("AlpSize");
        if (iVar4 != 0) {
          puVar7 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 != (undefined4 *)0x0) {
            FUN_008917b4(puVar7);
          }
        }
        iVar4 = FUN_007300a0(&DAT_00c408b8);
        if (iVar4 == 0) {
LAB_007ea74e:
          iVar4 = 0;
        }
        else {
          puVar7 = (undefined4 *)(iVar4 + 0x30);
          if (0xf < *(uint *)(iVar4 + 0x44)) {
            puVar7 = (undefined4 *)*puVar7;
          }
          if (puVar7 == (undefined4 *)0x0) goto LAB_007ea74e;
          iVar4 = FUN_008917b4(puVar7);
        }
        if ((local_54 == 0) && (iVar4 == 0)) {
          iVar4 = FUN_00891268(0x84);
          local_8._0_1_ = 1;
          if (iVar4 == 0) {
            iVar4 = 0;
          }
          else {
            ppppuVar11 = (undefined4 ****)local_30[0];
            if (local_1c < 0x10) {
              ppppuVar11 = local_30;
            }
            iVar4 = FUN_007f7680(iVar4,ppppuVar11,0);
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00402a70(&DAT_00c0cec8,4);
          if (*(int *)(iVar4 + 0x38) != 0) {
            FUN_00891d3d(*(int *)(iVar4 + 0x38));
            *(undefined4 *)(iVar4 + 0x38) = 0;
          }
          uVar8 = FUN_0087dc3d(0x1000);
          *(undefined4 *)(iVar4 + 0x38) = uVar8;
          *(undefined4 *)(iVar4 + 0x3c) = 0x40;
        }
        else {
          iVar9 = FUN_00891268(0x84);
          local_8._0_1_ = 2;
          if (iVar9 == 0) {
            iVar4 = 0;
          }
          else {
            ppppuVar11 = (undefined4 ****)local_30[0];
            if (local_1c < 0x10) {
              ppppuVar11 = local_30;
            }
            iVar4 = FUN_007f7680(iVar9,ppppuVar11,iVar4);
          }
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00402a70(&DAT_00c0cec8,4);
          iVar9 = local_54 * 0x18;
          local_50[0] = FUN_0087dc3d(*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x68 + iVar9));
          (**(code **)(**(int **)(param_1 + 0x24) + 0x34))
                    (*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x58 + iVar9),0);
          if (*(int **)(param_1 + 0x24) != (int *)0x0) {
            (**(code **)(**(int **)(param_1 + 0x24) + 0x10))
                      (local_50[0],1,*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x68 + iVar9));
          }
          _Src = (void *)FUN_0087dc3d(*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x6c + iVar9));
          FUN_00727190(_Src);
          _Size = *(size_t *)(iVar9 + 0x6c + *(int *)(param_1 + 0x28));
          uVar8 = *(undefined4 *)(iVar9 + 0x5c + *(int *)(param_1 + 0x28));
          if (*(int *)(iVar4 + 0x38) != 0) {
            FUN_00891d3d(*(int *)(iVar4 + 0x38));
            *(undefined4 *)(iVar4 + 0x38) = 0;
          }
          _Dst = (void *)FUN_0087dc3d(_Size);
          *(void **)(iVar4 + 0x38) = _Dst;
          FID_conflict__memcpy(_Dst,_Src,_Size);
          *(undefined4 *)(iVar4 + 0x3c) = uVar8;
          if (local_50[0] != 0) {
            FUN_00891d3d(local_50[0]);
          }
          if (_Src != (void *)0x0) {
            FUN_00891d3d(_Src);
          }
        }
        local_38 = 0xf;
        local_3c = 0;
        local_50[1] = local_50[1] & 0xffffff00;
        FUN_00402a70(&DAT_00c0cec8,4);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_00401ed0(local_30,0,0xffffffff);
        *(float *)(iVar4 + 0x2c) = local_60;
        *(float *)(iVar4 + 0x28) = local_64;
        iVar9 = *(int *)(*(int *)(param_1 + 4) + 0x40);
        piVar10 = *(int **)(iVar9 + 0x188);
        local_50[0] = iVar4;
        if (local_50 < piVar10) {
          piVar2 = *(int **)(iVar9 + 0x184);
          if (local_50 < piVar2) goto LAB_007ea9b1;
          if (piVar10 == *(int **)(iVar9 + 0x18c)) {
            FUN_00797930();
          }
          if (*(undefined4 **)(iVar9 + 0x188) != (undefined4 *)0x0) {
            **(undefined4 **)(iVar9 + 0x188) =
                 *(undefined4 *)(*(int *)(iVar9 + 0x184) + ((int)local_50 - (int)piVar2 >> 2) * 4);
          }
        }
        else {
LAB_007ea9b1:
          if (piVar10 == *(int **)(iVar9 + 0x18c)) {
            FUN_00797930();
          }
          if (*(int **)(iVar9 + 0x188) != (int *)0x0) {
            **(int **)(iVar9 + 0x188) = iVar4;
          }
        }
        *(int *)(iVar9 + 0x188) = *(int *)(iVar9 + 0x188) + 4;
        local_54 = local_54 + 1;
        if (0xf < local_38) {
          FUN_0089120c(local_50[1]);
        }
        local_8 = 0xffffffff;
        local_38 = 0xf;
        local_3c = 0;
        local_50[1] = local_50[1] & 0xffffff00;
        if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
      }
      for (in_ECX = (int *)in_ECX[0x10]; in_ECX != (int *)0x0; in_ECX = (int *)in_ECX[0x10]) {
        piVar10 = in_ECX + 8;
        if (0xf < (uint)in_ECX[0xd]) {
          piVar10 = (int *)*piVar10;
        }
        iVar4 = __stricmp((char *)piVar10,"Layer");
        if (iVar4 == 0) goto LAB_007eaa56;
      }
      in_ECX = (int *)0x0;
LAB_007eaa56:
    } while (in_ECX != (int *)0x0);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

