
void FUN_00845720(undefined8 *param_1,undefined8 *param_2,uint param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  int iVar9;
  uint uVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  
  iVar9 = FUN_00847e10();
  if ((*(byte *)(iVar9 + 4) >> 3 & 1) == 0) {
    uVar10 = param_3 & 3;
    for (param_3 = param_3 >> 2; param_3 != 0; param_3 = param_3 - 1) {
      *(undefined4 *)param_1 = *(undefined4 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 4);
      param_1 = (undefined8 *)((int)param_1 + 4);
    }
    for (; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined1 *)param_1 = *(undefined1 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 1);
      param_1 = (undefined8 *)((int)param_1 + 1);
    }
  }
  else {
    if (0x3f < param_3) {
      if ((param_3 < 0x8001) || (0x10000 < param_3)) {
        uVar10 = 8U - (int)param_1 & 7;
        param_3 = param_3 - uVar10;
        puVar12 = param_2;
        puVar11 = param_2;
        puVar14 = param_1;
        puVar13 = param_1;
        switch(uVar10) {
        case 7:
          puVar14 = (undefined8 *)((int)param_1 + 1);
          puVar12 = (undefined8 *)((int)param_2 + 1);
          *(undefined1 *)param_1 = *(undefined1 *)param_2;
        case 6:
          puVar13 = (undefined8 *)((int)puVar14 + 1);
          puVar11 = (undefined8 *)((int)puVar12 + 1);
          *(undefined1 *)puVar14 = *(undefined1 *)puVar12;
        case 5:
          param_1 = (undefined8 *)((int)puVar13 + 1);
          param_2 = (undefined8 *)((int)puVar11 + 1);
          *(undefined1 *)puVar13 = *(undefined1 *)puVar11;
        case 4:
          puVar14 = (undefined8 *)((int)param_1 + 1);
          puVar12 = (undefined8 *)((int)param_2 + 1);
          *(undefined1 *)param_1 = *(undefined1 *)param_2;
        case 3:
          param_1 = (undefined8 *)((int)puVar14 + 1);
          param_2 = (undefined8 *)((int)puVar12 + 1);
          *(undefined1 *)puVar14 = *(undefined1 *)puVar12;
        case 2:
          puVar14 = (undefined8 *)((int)param_1 + 1);
          puVar12 = (undefined8 *)((int)param_2 + 1);
          *(undefined1 *)param_1 = *(undefined1 *)param_2;
        case 1:
          param_1 = (undefined8 *)((int)puVar14 + 1);
          param_2 = (undefined8 *)((int)puVar12 + 1);
          *(undefined1 *)puVar14 = *(undefined1 *)puVar12;
        }
      }
      uVar10 = param_3 >> 6;
      if (uVar10 != 0) {
        if (uVar10 < 0x400) {
          do {
            uVar1 = param_2[1];
            *param_1 = *param_2;
            param_1[1] = uVar1;
            uVar1 = param_2[3];
            param_1[2] = param_2[2];
            param_1[3] = uVar1;
            uVar1 = param_2[5];
            param_1[4] = param_2[4];
            param_1[5] = uVar1;
            uVar1 = param_2[7];
            param_1[6] = param_2[6];
            param_1[7] = uVar1;
            param_2 = param_2 + 8;
            param_1 = param_1 + 8;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
        }
        else {
          if (0xc4f < uVar10) {
            for (; 0x7f < (int)uVar10; uVar10 = uVar10 - 0x80) {
              iVar9 = 0x40;
              param_2 = param_2 + 0x400;
              do {
                param_2 = param_2 + -0x10;
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
              iVar9 = 0x80;
              do {
                uVar1 = *param_2;
                uVar2 = param_2[1];
                uVar3 = param_2[2];
                uVar4 = param_2[3];
                uVar5 = param_2[4];
                uVar6 = param_2[5];
                uVar7 = param_2[6];
                uVar8 = param_2[7];
                param_2 = param_2 + 8;
                *param_1 = uVar1;
                param_1[1] = uVar2;
                param_1[2] = uVar3;
                param_1[3] = uVar4;
                param_1[4] = uVar5;
                param_1[5] = uVar6;
                param_1[6] = uVar7;
                param_1[7] = uVar8;
                param_1 = param_1 + 8;
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
            }
          }
          for (; uVar10 != 0; uVar10 = uVar10 - 1) {
            uVar1 = param_2[1];
            uVar2 = param_2[2];
            *param_1 = *param_2;
            uVar3 = param_2[3];
            param_1[1] = uVar1;
            uVar1 = param_2[4];
            param_1[2] = uVar2;
            uVar2 = param_2[5];
            param_1[3] = uVar3;
            uVar3 = param_2[6];
            param_1[4] = uVar1;
            uVar1 = param_2[7];
            param_1[5] = uVar2;
            param_1[6] = uVar3;
            param_1[7] = uVar1;
            param_2 = param_2 + 8;
            param_1 = param_1 + 8;
          }
        }
      }
    }
    puVar12 = param_2;
    puVar11 = param_2;
    puVar14 = param_1;
    puVar13 = param_1;
    switch(param_3 >> 2 & 0xf) {
    case 0xf:
      puVar14 = (undefined8 *)((int)param_1 + 4);
      puVar12 = (undefined8 *)((int)param_2 + 4);
      *(undefined4 *)param_1 = *(undefined4 *)param_2;
    case 0xe:
      puVar13 = (undefined8 *)((int)puVar14 + 4);
      puVar11 = (undefined8 *)((int)puVar12 + 4);
      *(undefined4 *)puVar14 = *(undefined4 *)puVar12;
    case 0xd:
      param_1 = (undefined8 *)((int)puVar13 + 4);
      param_2 = (undefined8 *)((int)puVar11 + 4);
      *(undefined4 *)puVar13 = *(undefined4 *)puVar11;
    case 0xc:
      puVar14 = (undefined8 *)((int)param_1 + 4);
      puVar12 = (undefined8 *)((int)param_2 + 4);
      *(undefined4 *)param_1 = *(undefined4 *)param_2;
    case 0xb:
      param_1 = (undefined8 *)((int)puVar14 + 4);
      param_2 = (undefined8 *)((int)puVar12 + 4);
      *(undefined4 *)puVar14 = *(undefined4 *)puVar12;
    case 10:
      puVar14 = (undefined8 *)((int)param_1 + 4);
      puVar12 = (undefined8 *)((int)param_2 + 4);
      *(undefined4 *)param_1 = *(undefined4 *)param_2;
    case 9:
      param_1 = (undefined8 *)((int)puVar14 + 4);
      param_2 = (undefined8 *)((int)puVar12 + 4);
      *(undefined4 *)puVar14 = *(undefined4 *)puVar12;
    case 8:
      puVar14 = (undefined8 *)((int)param_1 + 4);
      puVar12 = (undefined8 *)((int)param_2 + 4);
      *(undefined4 *)param_1 = *(undefined4 *)param_2;
    case 7:
      param_1 = (undefined8 *)((int)puVar14 + 4);
      param_2 = (undefined8 *)((int)puVar12 + 4);
      *(undefined4 *)puVar14 = *(undefined4 *)puVar12;
    case 6:
      puVar14 = (undefined8 *)((int)param_1 + 4);
      puVar12 = (undefined8 *)((int)param_2 + 4);
      *(undefined4 *)param_1 = *(undefined4 *)param_2;
    case 5:
      param_1 = (undefined8 *)((int)puVar14 + 4);
      param_2 = (undefined8 *)((int)puVar12 + 4);
      *(undefined4 *)puVar14 = *(undefined4 *)puVar12;
    case 4:
      puVar14 = (undefined8 *)((int)param_1 + 4);
      puVar12 = (undefined8 *)((int)param_2 + 4);
      *(undefined4 *)param_1 = *(undefined4 *)param_2;
    case 3:
      param_1 = (undefined8 *)((int)puVar14 + 4);
      param_2 = (undefined8 *)((int)puVar12 + 4);
      *(undefined4 *)puVar14 = *(undefined4 *)puVar12;
    case 2:
      puVar14 = (undefined8 *)((int)param_1 + 4);
      puVar12 = (undefined8 *)((int)param_2 + 4);
      *(undefined4 *)param_1 = *(undefined4 *)param_2;
    case 1:
      param_1 = (undefined8 *)((int)puVar14 + 4);
      param_2 = (undefined8 *)((int)puVar12 + 4);
      *(undefined4 *)puVar14 = *(undefined4 *)puVar12;
    case 0:
      param_3 = param_3 & 3;
      if (param_3 != 0) {
        for (; param_3 != 0; param_3 = param_3 - 1) {
          *(undefined1 *)param_1 = *(undefined1 *)param_2;
          param_2 = (undefined8 *)((int)param_2 + 1);
          param_1 = (undefined8 *)((int)param_1 + 1);
        }
      }
    }
  }
  return;
}

