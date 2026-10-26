
byte FUN_00549660(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  float10 fVar3;
  char local_22;
  byte local_21;
  float local_20 [2];
  float local_18;
  float local_14;
  undefined1 local_10 [12];
  
  local_22 = *(char *)(*(int *)(unaff_ESI + 0x50) + 0xb0);
  local_21 = 1;
  iVar1 = FUN_0054aa60(param_2);
  if (iVar1 != 0) {
    if ((param_1 == 4) && (param_2 == 0)) {
      local_18 = *(float *)(unaff_ESI + 100) - *(float *)(*(int *)(unaff_ESI + 0x50) + 0xa0);
      local_14 = *(float *)(unaff_ESI + 0x68) - *(float *)(*(int *)(unaff_ESI + 0x50) + 0xa4);
      local_20[0] = local_18 * local_18 + local_14 * local_14;
      if (5.0 < local_20[0]) {
        iVar1 = FUN_0040f060();
        if (*(int *)(iVar1 + 0xa4) != 0) {
          iVar1 = FUN_0082d790(*(int *)(iVar1 + 0xa4),local_20,
                               *(undefined4 *)(*(int *)(unaff_ESI + 0x50) + 0xa0),
                               *(undefined4 *)(*(int *)(unaff_ESI + 0x50) + 0xa4),
                               *(undefined4 *)(unaff_ESI + 100),*(undefined4 *)(unaff_ESI + 0x68));
          if (iVar1 != 0) {
            if (iVar1 - 1U < 3) {
              fVar3 = (float10)FUN_0049aeb0();
              local_22 = FUN_004bb450((float)fVar3);
            }
            goto LAB_0054976d;
          }
        }
        fVar3 = (float10)FUN_0049aeb0();
        local_22 = FUN_004bb450((float)fVar3);
        goto LAB_0054976d;
      }
      local_22 = *(char *)(*(int *)(unaff_ESI + 0x54) + 0xb0);
    }
    else {
      local_18 = *(float *)(iVar1 + 0xa0) - *(float *)(*(int *)(unaff_ESI + 0x50) + 0xa0);
      local_14 = *(float *)(iVar1 + 0xa4) - *(float *)(*(int *)(unaff_ESI + 0x50) + 0xa4);
      local_20[0] = local_18 * local_18 + local_14 * local_14;
      if (25.0 < local_20[0]) {
        iVar2 = FUN_0040f060();
        if (*(int *)(iVar2 + 0xa4) == 0) {
          fVar3 = (float10)FUN_008fedca();
          local_20[0] = (float)fVar3 + 1.5707964;
          local_22 = FUN_004bb450(local_20[0]);
        }
        else {
          iVar1 = FUN_0082d790(*(int *)(iVar2 + 0xa4),local_10,
                               *(undefined4 *)(*(int *)(unaff_ESI + 0x50) + 0xa0),
                               *(undefined4 *)(*(int *)(unaff_ESI + 0x50) + 0xa4),
                               *(undefined4 *)(iVar1 + 0xa0),*(undefined4 *)(iVar1 + 0xa4));
          if (iVar1 == 0) {
            fVar3 = (float10)FUN_008fedca();
            local_20[0] = (float)fVar3 + 1.5707964;
            local_22 = FUN_004bb450(local_20[0]);
          }
          else if (iVar1 - 1U < 3) {
            fVar3 = (float10)FUN_0049aeb0();
            local_22 = FUN_004bb450((float)fVar3);
          }
        }
        goto LAB_0054976d;
      }
    }
  }
  local_21 = 0;
LAB_0054976d:
  if (param_3 != 0) {
    local_22 = local_22 + -0x80;
  }
  *(ushort *)(unaff_ESI + 0x72) = (ushort)local_21 << 0xf;
  *(char *)(unaff_ESI + 0x74) = local_22;
  return local_21;
}

