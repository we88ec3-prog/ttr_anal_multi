
void FUN_007ac030(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_EAX;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *local_c;
  undefined4 local_8;
  
  puVar3 = (undefined4 *)FUN_00891268(0x30);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = IS3D::CFieldPanel::vftable;
    puVar3[4] = 0x3f800000;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[9] = 0;
    puVar3[5] = 0;
    puVar3[10] = 0;
    puVar3[6] = 0;
    puVar3[0xb] = 0;
    puVar3[7] = 0;
  }
  puVar3[9] = param_2;
  puVar3[10] = param_3;
  puVar3[0xb] = param_4;
  switch(in_EAX) {
  case 0:
  case 2:
    local_8 = 0x41a00000;
    uVar2 = 0x41200000;
    break;
  case 1:
  case 3:
    local_8 = 0x42700000;
    uVar2 = 0x42480000;
    break;
  default:
    return;
  }
  local_c = puVar3;
  FUN_007bedc0(puVar3,0,local_8,uVar2,0,0,0);
  FUN_007bee40(0,0,0x43480000,0,0,0xc3af0000,0x3f800000,0x40000000,0xc0000000,0xbf800000,0xbf800000)
  ;
  FUN_007be770(puVar3);
  iVar1 = param_1[0x4f];
  puVar3[4] = iVar1;
  if (puVar3[1] != 0) {
    FUN_0077ef50(iVar1,iVar1,iVar1);
  }
  iVar1 = *param_1;
  iVar4 = FUN_0074d700(iVar1,*(undefined4 *)(iVar1 + 4),&local_c);
  if (param_1[1] != 0x3ffffffe) {
    param_1[1] = param_1[1] + 1;
    *(int *)(iVar1 + 4) = iVar4;
    **(int **)(iVar4 + 4) = iVar4;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("list<T> too long");
}

