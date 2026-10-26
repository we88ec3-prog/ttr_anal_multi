
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007912b0(int *param_1)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  float *pfVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  float10 fVar9;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  undefined8 uStack_9c;
  undefined8 uStack_94;
  float fStack_8c;
  float fStack_88;
  undefined1 auStack_74 [32];
  undefined1 auStack_54 [24];
  undefined1 auStack_3c [16];
  undefined1 auStack_2c [40];
  
  if ((param_1[1] != 2) && (param_1[1] != 4)) {
    if (DAT_00fe3218 == (undefined *)0x0) {
      if ((_DAT_00fe3534 & 1) == 0) {
        _DAT_00fe3534 = _DAT_00fe3534 | 1;
      }
      DAT_00fe3218 = &DAT_00fe3526;
    }
    iVar2 = (**(code **)(*param_1 + 0x18))();
    uStack_94 = (double)CONCAT44(uStack_94._4_4_,iVar2);
    uStack_9c._4_4_ = 0;
    if (0 < iVar2) {
      do {
        uVar7 = uStack_9c._4_4_;
        fStack_a4 = 0.0;
        fStack_a0 = 0.0;
        uStack_9c = (double)((ulonglong)uStack_9c._4_4_ << 0x20);
        fStack_b8 = 0.0;
        fStack_b4 = 0.0;
        fStack_b0 = 0.0;
        fStack_ac = 1.0;
        uVar3 = (**(code **)(*param_1 + 0x24))(uVar7);
        if ((uVar3 & 0x10) == 0) {
          iVar2 = param_1[6];
          if ((uint)((param_1[7] - iVar2) / 0x60) <= uVar7) goto LAB_00791718;
          iVar8 = uVar7 * 0x60;
          fStack_ac = *(float *)(iVar2 + 0x50 + iVar8);
          fStack_a4 = *(float *)(iVar2 + 0x58 + iVar8);
          fStack_a8 = *(float *)(iVar2 + 0x54 + iVar8);
          fStack_a0 = *(float *)(iVar2 + 0x5c + iVar8);
          if (fStack_ac < 0.0) {
            fStack_ac = -fStack_ac;
            fStack_a8 = -fStack_a8;
            fStack_a4 = -fStack_a4;
            fStack_a0 = -fStack_a0;
          }
          FUN_00781020(0x3f800000);
          uStack_94 = (double)(fStack_ac * 0.5);
          fVar9 = (float10)FUN_008ff0a0();
          fStack_bc = (float)((float10)fStack_a8 * fVar9);
          fStack_b8 = (float)((float10)fStack_a4 * fVar9);
          fStack_b4 = (float)(fVar9 * (float10)fStack_a0);
          fVar9 = (float10)FUN_008fef70();
          fStack_b0 = (float)fVar9;
          uVar7 = (uint)uStack_9c;
          if ((uint)uStack_9c != 0) {
            uVar6 = (**(code **)(*param_1 + 0x1c))(auStack_3c,(uint)uStack_9c - 1);
            pfVar5 = (float *)FUN_0077e880(uVar6);
            if (&fStack_bc != pfVar5) {
              fStack_b0 = pfVar5[3];
              fStack_bc = *pfVar5;
              fStack_b8 = pfVar5[1];
              fStack_b4 = pfVar5[2];
            }
          }
        }
        else {
          puVar4 = (undefined1 *)(**(code **)(*param_1 + 0x1c))(auStack_2c,uVar7);
          if (&stack0xffffff3c != puVar4) {
            fStack_b8 = *(float *)(puVar4 + 0xc);
            fStack_bc = *(float *)(puVar4 + 8);
          }
          FUN_00780480();
          if (fStack_a4 != 0.0) {
            pfVar5 = (float *)(**(code **)(*param_1 + 0x1c))(auStack_54,(int)fStack_a4 - 1);
            uStack_94 = (double)CONCAT44(-pfVar5[1],-*pfVar5);
            fStack_8c = -pfVar5[2];
            fStack_88 = pfVar5[3];
            FUN_0077e880(&stack0xffffff3c);
          }
          FUN_00780b80(&fStack_b4);
          FUN_00781020(0x3f800000);
          FUN_00796120();
          uStack_9c = (double)(fStack_b4 * 0.5);
          fVar9 = (float10)FUN_008ff0a0();
          fStack_bc = (float)(fVar9 * (float10)fStack_a8);
          fVar9 = (float10)FUN_008fef70();
          fVar1 = fStack_a4;
          fStack_b8 = (float)fVar9;
          if (fStack_a4 != 0.0) {
            uVar6 = (**(code **)(*param_1 + 0x1c))(auStack_74,(int)fStack_a4 - 1);
            puVar4 = (undefined1 *)FUN_0077e880(uVar6);
            if (&stack0xffffff3c != puVar4) {
              fStack_b8 = *(float *)(puVar4 + 0xc);
              fStack_bc = *(float *)(puVar4 + 8);
            }
          }
          iVar2 = *param_1;
          uVar7 = (**(code **)(iVar2 + 0x24))(fVar1);
          (**(code **)(iVar2 + 0x30))(fVar1,uVar7 & 0xffffffef);
          iVar2 = param_1[6];
          if ((uint)((param_1[7] - iVar2) / 0x60) <= (uint)fVar1) goto LAB_00791718;
          iVar8 = (int)fVar1 * 0x60;
          *(float *)(iVar2 + 0x54 + iVar8) = fStack_a8;
          *(float *)(iVar2 + 0x58 + iVar8) = fStack_a4;
          *(float *)(iVar2 + 0x5c + iVar8) = fStack_a0;
          if ((uint)((param_1[7] - param_1[6]) / 0x60) <= (uint)fVar1) goto LAB_00791718;
          *(float *)(param_1[6] + 0x50 + iVar8) = fStack_ac;
          (**(code **)(*param_1 + 0x28))(fVar1,fStack_bc,fStack_b8,fStack_b4,fStack_b0);
          uVar7 = (uint)uStack_9c;
        }
        iVar2 = param_1[6];
        if ((uint)((param_1[7] - iVar2) / 0x60) <= uVar7) {
LAB_00791718:
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid vector<T> subscript");
        }
        *(float *)(iVar2 + 0x54 + iVar8) = fStack_a8;
        *(float *)(iVar2 + 0x58 + iVar8) = fStack_a4;
        *(float *)(iVar2 + 0x5c + iVar8) = fStack_a0;
        if ((uint)((param_1[7] - param_1[6]) / 0x60) <= uVar7) goto LAB_00791718;
        *(float *)(param_1[6] + 0x50 + iVar8) = fStack_ac;
        (**(code **)(*param_1 + 0x28))(uVar7,fStack_bc,fStack_b8,fStack_b4,fStack_b0);
        uVar7 = uVar7 + 1;
        iVar2 = (int)uStack_94;
        uStack_9c._4_4_ = uVar7;
      } while ((int)uVar7 < (int)uStack_94);
    }
    iVar8 = 0;
    if (0 < iVar2) {
      do {
        FUN_00796260(iVar8,param_1);
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar2);
    }
    *(undefined1 *)(param_1 + 5) = 1;
  }
  return 1;
}

