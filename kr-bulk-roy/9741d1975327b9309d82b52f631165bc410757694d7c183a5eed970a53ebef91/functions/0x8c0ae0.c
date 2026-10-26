
int FUN_008c0ae0(undefined4 param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *in_EAX;
  uint *puVar3;
  undefined4 uVar4;
  undefined1 local_c [4];
  int local_8;
  
  local_8 = 0;
  puVar3 = (uint *)FUN_008baee0(param_2,0x2203c,&local_8);
  if (local_8 != 0) goto LAB_008c0d03;
  if (in_EAX == (undefined4 *)0x0) {
    in_EAX = &DAT_00bd74e0;
  }
  puVar3[9] = (uint)in_EAX;
  *(undefined2 *)(puVar3 + 3) = 0x7fff;
  puVar3[0x880e] = param_2;
  FUN_008bdf80(param_2);
  local_8 = FUN_008be2f0(param_1,puVar3,local_c);
  if (local_8 == 0) {
    uVar1 = puVar3[8];
    if (uVar1 != 0) {
      if (*(int *)(uVar1 + 0x1c) != 8) {
        *(undefined2 *)(uVar1 + 0x20) = *(undefined2 *)(uVar1 + 4);
      }
      uVar1 = puVar3[8];
      if (puVar3[1] != *(int *)(uVar1 + 0x40) + *(int *)(uVar1 + 0x34)) {
        *(undefined2 *)(uVar1 + 0x44084) = 1;
      }
      if ((*(int *)puVar3[9] != 0) &&
         ((uVar1 = puVar3[8], *(int *)(uVar1 + 0x34) != 0 || (*(int *)(uVar1 + 0x40) != 0)))) {
        if ((int)(short)puVar3[4] - (int)(short)puVar3[3] != (uint)*(ushort *)(uVar1 + 4)) {
          *(short *)(uVar1 + 4) = (short)puVar3[4] - (short)puVar3[3];
          *(undefined2 *)(puVar3[8] + 0x44084) = 1;
        }
        if (*(short *)(puVar3[8] + 8) != (short)puVar3[3]) {
          *(short *)(puVar3[8] + 8) = (short)puVar3[3];
          *(undefined2 *)(puVar3[8] + 0x44084) = 1;
        }
        if (*(short *)(puVar3[8] + 0xc) != *(short *)((int)puVar3 + 0x12)) {
          *(short *)(puVar3[8] + 0xc) = *(short *)((int)puVar3 + 0x12);
          *(undefined2 *)(puVar3[8] + 0x44084) = 1;
        }
        if (*(short *)(puVar3[8] + 0xe) != (short)puVar3[5]) {
          *(short *)(puVar3[8] + 0xe) = (short)puVar3[5];
          *(short *)(puVar3[8] + 10) = -(short)puVar3[5];
          *(undefined2 *)(puVar3[8] + 0x44084) = 1;
        }
        if ((int)(short)puVar3[5] + (int)*(short *)((int)puVar3 + 0x12) !=
            (uint)*(ushort *)(puVar3[8] + 6)) {
          *(short *)(puVar3[8] + 6) = (short)puVar3[5] + *(short *)((int)puVar3 + 0x12);
        }
      }
    }
    if ((*puVar3 & 1) != 0) {
      local_8 = ((*puVar3 & 0x20) != 0) + 0xb9;
      goto LAB_008c0d03;
    }
    uVar1 = puVar3[8];
    if (uVar1 == 0) {
      local_8 = 3;
    }
    else {
      iVar2 = *(int *)(uVar1 + 0x58);
      if (iVar2 != 0) {
        uVar4 = FUN_008bc7d0(*(undefined4 *)(uVar1 + 0x44088),1,iVar2,iVar2 + 1,
                             *(undefined4 *)(uVar1 + 0x54),&local_8);
        *(undefined4 *)(puVar3[8] + 0x54) = uVar4;
        if (local_8 != 0) goto LAB_008c0cc1;
        *(undefined1 *)(*(int *)(puVar3[8] + 0x58) + *(int *)(puVar3[8] + 0x54)) = 0;
      }
    }
    *param_3 = puVar3[8];
  }
  else {
LAB_008c0cc1:
    FUN_008bf890();
    FUN_008b9f80(param_2,puVar3[8]);
    puVar3[8] = 0;
  }
LAB_008c0d03:
  if (puVar3 != (uint *)0x0) {
    FUN_008bdfa0();
    FUN_008b9f80(param_2,puVar3);
  }
  return local_8;
}

