
int FUN_008bacd0(int param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  bool bVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  sbyte sVar9;
  byte *pbVar10;
  
  pbVar10 = param_2;
  bVar5 = false;
  if ((param_2 == (byte *)0x0) || (param_1 == 0)) {
    return 6;
  }
  bVar2 = *param_2;
  param_2 = (byte *)0x0;
  puVar7 = *(uint **)(param_1 + 0x20);
  while (bVar2 - 4 < 0x16) {
    switch(bVar2 - 4) {
    case 4:
      param_2 = (byte *)FUN_008babe0(param_1,*(undefined2 *)(pbVar10 + 2));
      if (param_2 == (byte *)0x0) {
        puVar8 = *(uint **)(param_1 + 0x20);
        bVar5 = true;
        goto LAB_008bae5b;
      }
      goto LAB_008bae73;
    default:
      goto switchD_008bad17_caseD_5;
    case 8:
    case 9:
      uVar6 = (uint)(byte)*puVar7;
      puVar8 = (uint *)((int)puVar7 + 1);
      sVar9 = 0x18;
      break;
    case 0xc:
    case 0xd:
      puVar8 = (uint *)((int)puVar7 + 2);
      uVar6 = (uint)CONCAT11((byte)*puVar7,*(byte *)((int)puVar7 + 1));
      sVar9 = 0x10;
      break;
    case 0xe:
    case 0xf:
      puVar8 = (uint *)((int)puVar7 + 2);
      uVar6 = (uint)(ushort)*puVar7;
      sVar9 = 0x10;
      break;
    case 0x10:
    case 0x11:
      puVar8 = puVar7 + 1;
      uVar6 = CONCAT31(CONCAT21(CONCAT11((byte)*puVar7,*(byte *)((int)puVar7 + 1)),
                                *(byte *)((int)puVar7 + 2)),*(byte *)((int)puVar7 + 3));
      sVar9 = 0;
      break;
    case 0x12:
    case 0x13:
      puVar8 = puVar7 + 1;
      uVar6 = *puVar7;
      sVar9 = 0;
      break;
    case 0x14:
    case 0x15:
      uVar4 = CONCAT11((byte)*puVar7,*(byte *)((int)puVar7 + 1));
      bVar3 = *(byte *)((int)puVar7 + 2);
      goto LAB_008bae2a;
    case 0x16:
    case 0x17:
                    /* WARNING: This code block may not be properly labeled as switch case */
      uVar4 = *(undefined2 *)((int)puVar7 + 1);
      bVar3 = (byte)*puVar7;
LAB_008bae2a:
      puVar8 = (uint *)((int)puVar7 + 3);
      uVar6 = (uint)CONCAT21(uVar4,bVar3);
      sVar9 = 8;
      break;
    case 0x18:
    case 0x19:
                    /* WARNING: This code block may not be properly labeled as switch case */
      puVar8 = (uint *)((uint)pbVar10[1] + (int)puVar7);
      if (puVar8 <= *(uint **)(param_1 + 0x24)) {
        if (bVar2 == 0x18) {
          FID_conflict__memcpy
                    ((void *)((uint)*(ushort *)(pbVar10 + 2) + param_3),puVar7,(uint)pbVar10[1]);
        }
        goto LAB_008bae5b;
      }
      param_2 = (byte *)0x55;
      goto LAB_008bae73;
    }
    if ((bVar2 & 1) != 0) {
      uVar6 = (int)(uVar6 << sVar9) >> sVar9;
    }
    puVar7 = (uint *)((uint)*(ushort *)(pbVar10 + 2) + param_3);
    if (pbVar10[1] == 1) {
      *(char *)puVar7 = (char)uVar6;
    }
    else if (pbVar10[1] == 2) {
      *(short *)puVar7 = (short)uVar6;
    }
    else {
      *puVar7 = uVar6;
    }
LAB_008bae5b:
    pbVar1 = pbVar10 + 4;
    pbVar10 = pbVar10 + 4;
    puVar7 = puVar8;
    bVar2 = *pbVar1;
  }
switchD_008bad17_caseD_5:
  *(uint **)(param_1 + 0x20) = puVar7;
LAB_008bae73:
  if (bVar5) {
    FUN_008baca0(param_1);
  }
  return (int)param_2;
}

