
void FUN_0076e570(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar10 = param_1[0x18];
  iVar1 = *(int *)(iVar10 + 0xc);
  iVar2 = param_1[2];
  iVar3 = *(int *)(iVar10 + 0x10);
  iVar4 = *(int *)(iVar10 + 8);
  iVar7 = *(int *)(iVar10 + 0x14);
  iVar9 = param_1[3];
  iVar5 = param_1[4];
  iVar6 = param_1[5];
  iVar8 = iVar9;
  iVar10 = iVar5;
  iVar11 = iVar2;
  switch(*(undefined4 *)(in_ECX + 8)) {
  case 0xc9:
    iVar11 = *(int *)(in_ECX + 0xc);
    iVar8 = *(int *)(in_ECX + 0x10);
    iVar10 = iVar11 + (iVar5 - iVar2);
    iVar6 = (iVar6 - iVar9) + iVar8;
    break;
  case 0xca:
    iVar10 = (*(int *)(in_ECX + 0x14) - iVar4) + iVar3;
    iVar11 = iVar10 + (iVar2 - iVar5);
    iVar8 = *(int *)(in_ECX + 0x10);
    iVar6 = (iVar6 - iVar9) + iVar8;
    break;
  case 0xcb:
    iVar11 = *(int *)(in_ECX + 0xc);
    iVar10 = iVar11 + (iVar5 - iVar2);
    goto LAB_0076e61b;
  case 0xcc:
    iVar10 = (*(int *)(in_ECX + 0x14) - iVar4) + iVar3;
    iVar11 = iVar10 + (iVar2 - iVar5);
    goto LAB_0076e61b;
  case 0xcd:
    iVar11 = *(int *)(in_ECX + 0xc);
    iVar10 = iVar11 + (iVar5 - iVar2);
    break;
  case 0xce:
    iVar10 = (*(int *)(in_ECX + 0x14) - iVar4) + iVar3;
    iVar11 = iVar10 + (iVar2 - iVar5);
    break;
  case 0xcf:
    iVar6 = (iVar6 - iVar9) + *(int *)(in_ECX + 0x10);
    iVar8 = *(int *)(in_ECX + 0x10);
    break;
  case 0xd0:
LAB_0076e61b:
    iVar7 = (*(int *)(in_ECX + 0x18) - iVar1) + iVar7;
    iVar9 = iVar9 - iVar6;
    iVar6 = iVar7;
    iVar8 = iVar7 + iVar9;
    break;
  case 0xd1:
    iVar9 = iVar9 - iVar6;
    iVar11 = ((iVar3 - iVar4) / 2 - (iVar5 - iVar2) / 2) + *(int *)(in_ECX + 0xc);
    iVar6 = (*(int *)(in_ECX + 0x18) - iVar1) + iVar7;
    iVar8 = iVar9 + iVar6;
    iVar10 = (iVar5 - iVar2) + iVar11;
    break;
  case 0xd2:
    iVar11 = ((iVar3 - iVar4) / 2 - (iVar5 - iVar2) / 2) + *(int *)(in_ECX + 0xc);
    iVar6 = (iVar6 - iVar9) + *(int *)(in_ECX + 0x10);
    iVar8 = *(int *)(in_ECX + 0x10);
    iVar10 = (iVar5 - iVar2) + iVar11;
    break;
  case 0xd3:
    iVar11 = *(int *)(in_ECX + 0xc);
    iVar10 = iVar11 + (iVar5 - iVar2);
    goto LAB_0076e6c6;
  case 0xd4:
    iVar10 = (*(int *)(in_ECX + 0x14) - iVar4) + iVar3;
    iVar8 = ((iVar7 - iVar1) / 2 - (iVar6 - iVar9) / 2) + *(int *)(in_ECX + 0x10);
    iVar6 = (iVar6 - iVar9) + iVar8;
    iVar11 = iVar10 + (iVar2 - iVar5);
    break;
  case 0xd5:
    iVar11 = ((iVar3 - iVar4) / 2 - (iVar5 - iVar2) / 2) + *(int *)(in_ECX + 0xc);
    iVar10 = (iVar5 - iVar2) + iVar11;
LAB_0076e6c6:
    iVar8 = ((iVar7 - iVar1) / 2 - (iVar6 - iVar9) / 2) + *(int *)(in_ECX + 0x10);
    iVar6 = (iVar6 - iVar9) + iVar8;
    break;
  case 0xd6:
    iVar8 = *(int *)(in_ECX + 0x10);
    iVar10 = (*(int *)(in_ECX + 0x14) - iVar4) + iVar3;
    iVar7 = (iVar6 - iVar9) + iVar8;
    goto LAB_0076e84e;
  case 0xd7:
    iVar10 = (*(int *)(in_ECX + 0x14) - iVar4) + iVar3;
    iVar7 = (*(int *)(in_ECX + 0x18) - iVar1) + iVar7;
    iVar8 = iVar7 + (iVar9 - iVar6);
    goto LAB_0076e84e;
  case 0xd8:
    iVar6 = (*(int *)(in_ECX + 0x18) - iVar1) + iVar7;
    iVar8 = *(int *)(in_ECX + 0x10);
    iVar10 = *(int *)(in_ECX + 0xc) + (iVar5 - iVar2);
    iVar11 = *(int *)(in_ECX + 0xc);
    break;
  case 0xd9:
    iVar10 = (*(int *)(in_ECX + 0x14) - iVar4) + iVar3;
    iVar6 = (*(int *)(in_ECX + 0x18) - iVar1) + iVar7;
    iVar8 = *(int *)(in_ECX + 0x10);
    iVar11 = iVar10 + (iVar2 - iVar5);
    break;
  case 0xda:
    iVar10 = (*(int *)(in_ECX + 0x14) - iVar4) + iVar3;
    iVar8 = *(int *)(in_ECX + 0x10);
    iVar7 = (*(int *)(in_ECX + 0x18) - iVar1) + iVar7;
    goto LAB_0076e84e;
  case 0xdb:
    iVar10 = (*(int *)(in_ECX + 0x14) - iVar4) + iVar3;
    iVar7 = iVar6;
LAB_0076e84e:
    iVar6 = iVar7;
    iVar11 = *(int *)(in_ECX + 0xc);
    break;
  case 0xdc:
    iVar6 = (*(int *)(in_ECX + 0x18) - iVar1) + iVar7;
    iVar8 = *(int *)(in_ECX + 0x10);
    break;
  default:
    goto switchD_0076e5d6_default;
  }
  (**(code **)(*param_1 + 0xbc))(iVar11,iVar8,iVar10,iVar6);
switchD_0076e5d6_default:
  return;
}

