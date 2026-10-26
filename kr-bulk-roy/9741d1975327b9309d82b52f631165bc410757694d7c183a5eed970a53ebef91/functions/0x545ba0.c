
undefined4 FUN_00545ba0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  float fVar8;
  
  if (((*(int *)(in_ECX + 4) != 0) && (fVar8 = *(float *)(in_ECX + 0x84), 0.0 < fVar8)) &&
     (*(int *)(in_ECX + 0xc) != 0)) {
    uVar2 = (uint)(byte)s___AVCCheckPointMgr___00f7f51c[0x15];
    uVar3 = (uint)(byte)s___AVCCheckPointMgr___00f7f51c[0x16];
    s___AVCCheckPointMgr___00f7f51c[0x15] = s___AVCCheckPointMgr___00f7f51c[0x15] + '\x01';
    s___AVCCheckPointMgr___00f7f51c[0x16] = s___AVCCheckPointMgr___00f7f51c[0x16] + '\x01';
    uVar4 = (uint)(byte)s___AVCCheckPointMgr___00f7f51c[0x17];
    s___AVCCheckPointMgr___00f7f51c[0x17] = s___AVCCheckPointMgr___00f7f51c[0x17] + '\x01';
    uVar4 = ((uVar2 | 0xffffff00) << 8 | uVar3) << 8 | uVar4;
    puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x4c))();
    uVar5 = *puVar1;
    uVar6 = puVar1[1];
    uVar7 = puVar1[2];
    FUN_00434740(uVar5,uVar6,uVar7,fVar8,uVar4);
    FUN_0079af30(uVar5,uVar6,uVar7,fVar8,uVar4);
  }
  return 0;
}

