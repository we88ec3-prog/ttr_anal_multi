
void FUN_007114d0(void)

{
  int *piVar1;
  int *piVar2;
  undefined2 uVar3;
  int in_EAX;
  undefined4 uVar4;
  int iVar5;
  undefined1 local_34 [24];
  undefined4 local_1c;
  int local_14;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = *(int **)(in_EAX + 0x30);
  uVar4 = FUN_0070d950();
  iVar5 = *(int *)(in_EAX + 0x30);
  if (200 < *(byte *)(iVar5 + 0x32) + 1) {
    uVar4 = FUN_0070d7c0();
    in_EAX = iVar5;
  }
  uVar3 = FUN_0070da10(in_EAX,uVar4);
  *(undefined2 *)(iVar5 + 0xac + (uint)*(byte *)(iVar5 + 0x32) * 2) = uVar3;
  local_c = 0xffffffff;
  local_8 = 0xffffffff;
  local_14 = piVar1[9];
  iVar5 = local_14 + 1;
  local_1c = 6;
  if ((int)(uint)*(byte *)(*piVar1 + 0x4b) < iVar5) {
    if (0xf9 < iVar5) {
                    /* WARNING: Subroutine does not return */
      FUN_006ff130(piVar1[3],"function or expression too complex",*(undefined4 *)(piVar1[3] + 0x10))
      ;
    }
    *(char *)(*piVar1 + 0x4b) = (char)iVar5;
  }
  piVar1[9] = piVar1[9] + 1;
  piVar2 = *(int **)(in_EAX + 0x30);
  *(char *)((int)piVar2 + 0x32) = *(char *)((int)piVar2 + 0x32) + '\x01';
  *(int *)(*(int *)(*piVar2 + 0x18) + 4 +
          (uint)*(ushort *)((int)piVar2 + (uint)*(byte *)((int)piVar2 + 0x32) * 2 + 0xaa) * 0xc) =
       piVar2[6];
  FUN_0070ef60(in_EAX,local_34,0,*(undefined4 *)(in_EAX + 4));
  FUN_00712880(local_34);
  *(int *)(*(int *)(*piVar1 + 0x18) + 4 +
          (uint)*(ushort *)((int)piVar1 + (uint)*(byte *)((int)piVar1 + 0x32) * 2 + 0xaa) * 0xc) =
       piVar1[6];
  return;
}

