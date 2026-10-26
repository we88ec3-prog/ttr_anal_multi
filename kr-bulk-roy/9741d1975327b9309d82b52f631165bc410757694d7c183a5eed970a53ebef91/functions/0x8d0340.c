
undefined4 FUN_008d0340(undefined4 *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  byte *unaff_EDI;
  
  pbVar4 = (byte *)*param_1;
  iVar5 = 0;
  uVar2 = 3;
  pbVar3 = pbVar4;
  if (unaff_EDI <= pbVar4) {
LAB_008d03b8:
    *param_1 = pbVar4;
    return uVar2;
  }
  do {
    bVar1 = *pbVar3;
    pbVar4 = pbVar3 + 1;
    if (bVar1 == 0x5c) {
      uVar2 = 3;
      if (pbVar4 == unaff_EDI) goto LAB_008d03b8;
      switch(*pbVar4) {
      case 0x28:
      case 0x29:
      case 0x5c:
      case 0x62:
      case 0x66:
      case 0x6e:
      case 0x72:
      case 0x74:
        pbVar4 = pbVar3 + 2;
        break;
      default:
        uVar6 = 0;
        do {
          uVar2 = 3;
          if (unaff_EDI <= pbVar4) goto LAB_008d03b8;
          if ((*pbVar4 < 0x30) || (0x37 < *pbVar4)) break;
          uVar6 = uVar6 + 1;
          pbVar4 = pbVar4 + 1;
        } while (uVar6 < 3);
      }
    }
    else if (bVar1 == 0x28) {
      iVar5 = iVar5 + 1;
    }
    else if ((bVar1 == 0x29) && (iVar5 = iVar5 + -1, iVar5 == 0)) {
      uVar2 = 0;
      goto LAB_008d03b8;
    }
    pbVar3 = pbVar4;
    if (unaff_EDI <= pbVar4) {
      *param_1 = pbVar4;
      return 3;
    }
  } while( true );
}

