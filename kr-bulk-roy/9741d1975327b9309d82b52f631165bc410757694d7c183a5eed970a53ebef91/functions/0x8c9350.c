
int FUN_008c9350(int param_1)

{
  undefined4 uVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  int in_EDX;
  uint uVar5;
  uint local_10;
  code *local_c;
  uint local_8;
  
  uVar1 = *(undefined4 *)(in_EDX + 4);
  if (*(uint *)(in_EDX + 0x18) < (uint)(in_EAX + in_ECX)) {
    return 6;
  }
  iVar2 = FUN_008b97e0(uVar1,*(int *)(in_EDX + 0x14) + in_EAX);
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = FUN_008bc7a0(uVar1);
  if (iVar2 != 0) {
    return iVar2;
  }
  local_c = (code *)(param_1 + -1);
  local_8 = local_10;
  switch(param_1) {
  case 1:
  case 2:
  case 8:
  case 0x11:
    break;
  default:
    iVar2 = 0;
    goto LAB_008c93e3;
  case 6:
  case 7:
  case 9:
  case 0x12:
  }
  iVar2 = FUN_008c8e10();
  if (iVar2 != 0) goto LAB_008c948d;
LAB_008c93e3:
  uVar3 = local_8;
  switch(local_c) {
  case (code *)0x1:
  case (code *)0x6:
    local_c = FUN_008c8e90;
    break;
  case (code *)0x2:
  case (code *)0x7:
    uVar5 = (uint)(*(ushort **)(in_EDX + 0xc))[1];
    uVar3 = (uint)**(ushort **)(in_EDX + 0xc);
    uVar4 = (uVar5 + 7 >> 3) * uVar3;
    if ((uVar4 <= uVar3 * uVar5 + 7 >> 3) || (uVar4 - ((local_10 + in_ECX) - local_8) != 0))
    goto switchD_008c93f3_caseD_5;
    local_c = FUN_008c8e90;
    break;
  default:
    iVar2 = 8;
    goto LAB_008c948d;
  case (code *)0x5:
switchD_008c93f3_caseD_5:
    local_c = FUN_008c9010;
    break;
  case (code *)0x8:
    uVar3 = local_8 + 1;
    if (local_10 + in_ECX < local_8 + 1) goto LAB_008c948d;
  case (code *)0x9:
    local_8 = uVar3;
    local_c = FUN_008c9220;
    break;
  case (code *)0x11:
  case (code *)0x12:
  case (code *)0x13:
                    /* WARNING: This code block may not be properly labeled as switch case */
    iVar2 = 7;
    goto LAB_008c948d;
  }
  if ((*(char *)(in_EDX + 0x11) != '\0') || (iVar2 = FUN_008c8d10(), iVar2 == 0)) {
    iVar2 = (*local_c)();
  }
LAB_008c948d:
  FUN_008bab90(uVar1,&local_10);
  return iVar2;
}

