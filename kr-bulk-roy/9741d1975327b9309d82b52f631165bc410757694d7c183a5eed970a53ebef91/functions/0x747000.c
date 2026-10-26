
undefined4 * FUN_00747000(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f1c8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (50000 < param_1) {
    if (param_1 < 0xc47d) {
      if (param_1 == 0xc47c) {
        ExceptionList = &local_10;
        puVar3 = _malloc(0xf0);
        local_8 = 0x3b;
        if (puVar3 == (undefined4 *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        FUN_007564e0();
        *puVar3 = FoxUI::FXUIWindowSimple::vftable;
        puVar3[0x3b] = 0;
        ExceptionList = local_10;
        return puVar3;
      }
      switch(param_1) {
      case 0xc351:
        goto switchD_00747859_caseD_c351;
      case 0xc352:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0x110);
        local_8 = 0x21;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0074a3f0();
        ExceptionList = local_10;
        return puVar3;
      case 0xc353:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xd8);
        local_8 = 0x26;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0076cdc0();
        ExceptionList = local_10;
        return puVar3;
      case 0xc354:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xbc);
        local_8 = 0x27;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0076cbe0();
        ExceptionList = local_10;
        return puVar3;
      case 0xc355:
        ExceptionList = &local_10;
        puVar3 = _malloc(0xe0);
        local_8 = 0x28;
        if (puVar3 == (undefined4 *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        FUN_0075da10();
        *puVar3 = FoxUI::FXUIWindowClientScrollBar::vftable;
        ExceptionList = local_10;
        return puVar3;
      case 0xc356:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xcc);
        local_8 = 0x25;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0075af30();
        ExceptionList = local_10;
        return puVar3;
      case 0xc357:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xd8);
        local_8 = 0x2b;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0076a500();
        ExceptionList = local_10;
        return puVar3;
      case 0xc358:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xdc);
        local_8 = 0x2c;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0076aa30();
        ExceptionList = local_10;
        return puVar3;
      case 0xc359:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xdc);
        local_8 = 0x2d;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0076ac70();
        ExceptionList = local_10;
        return puVar3;
      case 0xc35a:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xe0);
        local_8 = 0x2e;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0076aec0();
        ExceptionList = local_10;
        return puVar3;
      case 0xc35b:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xdc);
        local_8 = 0x2f;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0076b1e0();
        ExceptionList = local_10;
        return puVar3;
      case 0xc35c:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xdc);
        local_8 = 0x30;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0076b2e0();
        ExceptionList = local_10;
        return puVar3;
      case 0xc35d:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xe0);
        local_8 = 0x31;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0076b530();
        ExceptionList = local_10;
        return puVar3;
      case 0xc35e:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xd8);
        local_8 = 0x32;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0076a9b0();
        ExceptionList = local_10;
        return puVar3;
      default:
        return (undefined4 *)0x0;
      case 0xc3b4:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xf8);
        local_8 = 0x33;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0076f4c0();
        ExceptionList = local_10;
        return puVar3;
      case 0xc3b5:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0x11c);
        local_8 = 0x34;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0074b070();
        ExceptionList = local_10;
        return puVar3;
      case 0xc3b6:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0x110);
        local_8 = 0x24;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0076d540();
        ExceptionList = local_10;
        return puVar3;
      case 0xc3b7:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xf8);
        local_8 = 0x35;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_00488ea0();
        ExceptionList = local_10;
        return puVar3;
      case 0xc3b8:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0x11c);
        local_8 = 0x36;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0074b410();
        ExceptionList = local_10;
        return puVar3;
      case 0xc418:
        ExceptionList = &local_10;
        puVar3 = _malloc(0xec);
        local_8 = 0x37;
        if (puVar3 == (undefined4 *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        FUN_007564e0();
        *puVar3 = FoxUI::FXUIWindowThin::vftable;
        ExceptionList = local_10;
        return puVar3;
      case 0xc419:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0x110);
        local_8 = 0x38;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_004285e0();
        ExceptionList = local_10;
        return puVar3;
      case 0xc41a:
        ExceptionList = &local_10;
        puVar3 = _malloc(0xcc);
        local_8 = 0x29;
        if (puVar3 == (undefined4 *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        FUN_0075af30();
        *puVar3 = FoxUI::FXUIWindowClientThin::vftable;
        ExceptionList = local_10;
        return puVar3;
      case 0xc41b:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xd8);
        local_8 = 0x2a;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0075b9d0();
        ExceptionList = local_10;
        return puVar3;
      case 0xc41c:
        ExceptionList = &local_10;
        puVar3 = _malloc(0xec);
        local_8 = 0x39;
        if (puVar3 == (undefined4 *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        FUN_007564e0();
        *puVar3 = FoxUI::FXUIWindowThinScroll::vftable;
        ExceptionList = local_10;
        return puVar3;
      case 0xc41d:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0x110);
        local_8 = 0x3a;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0074bef0();
        ExceptionList = local_10;
        return puVar3;
      }
    }
    if (53000 < param_1) {
      return (undefined4 *)0x0;
    }
    if (param_1 != 53000) {
      switch(param_1) {
      case 0xc47d:
        goto switchD_00747e40_caseD_c47d;
      case 0xc47e:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xf0);
        local_8 = 0x3d;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_00487290();
        ExceptionList = local_10;
        return puVar3;
      case 0xc47f:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0x114);
        local_8 = 0x3e;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0074c400();
        ExceptionList = local_10;
        return puVar3;
      default:
        return (undefined4 *)0x0;
      case 0xc4e0:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xf4);
        local_8 = 0x3f;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_00755e20();
        ExceptionList = local_10;
        return puVar3;
      case 0xc4e1:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0x118);
        local_8 = 0x40;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_00646c00();
        ExceptionList = local_10;
        return puVar3;
      case 0xc4e2:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0x104);
        local_8 = 0x23;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0075abc0();
        ExceptionList = local_10;
        return puVar3;
      case 0xc4e3:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xf4);
        local_8 = 0x41;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_004889f0();
        ExceptionList = local_10;
        return puVar3;
      case 0xc4e4:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0x118);
        local_8 = 0x42;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_0074ceb0();
        ExceptionList = local_10;
        return puVar3;
      case 0xc545:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xf4);
        local_8 = 0x47;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_00487770();
        ExceptionList = local_10;
        return puVar3;
      case 0xc546:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xf4);
        local_8 = 0x48;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_00487a40();
        ExceptionList = local_10;
        return puVar3;
      case 0xc547:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xf4);
        local_8 = 0x49;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_00487d10();
        ExceptionList = local_10;
        return puVar3;
      case 0xc548:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xf4);
        local_8 = 0x44;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_00487ff0();
        ExceptionList = local_10;
        return puVar3;
      case 0xc549:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xf4);
        local_8 = 0x45;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_00488230();
        ExceptionList = local_10;
        return puVar3;
      case 0xc54a:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xf4);
        local_8 = 0x46;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_00488510();
        ExceptionList = local_10;
        return puVar3;
      case 0xc54b:
        ExceptionList = &local_10;
        pvVar2 = _malloc(0xf4);
        local_8 = 0x43;
        if (pvVar2 == (void *)0x0) {
          ExceptionList = local_10;
          return (undefined4 *)0x0;
        }
        puVar3 = (undefined4 *)FUN_00487530();
        ExceptionList = local_10;
        return puVar3;
      }
    }
    ExceptionList = &local_10;
    puVar3 = _malloc(0x80);
    local_8 = 0x4a;
    if (puVar3 == (undefined4 *)0x0) {
      ExceptionList = local_10;
      return (undefined4 *)0x0;
    }
    FUN_007451f0(uVar1);
    *puVar3 = FoxUI::FXUIDummy::vftable;
    ExceptionList = local_10;
    return puVar3;
  }
  if (param_1 == 50000) {
    ExceptionList = &local_10;
    pvVar2 = _malloc(0xec);
    local_8 = 0x20;
    if (pvVar2 == (void *)0x0) {
      ExceptionList = local_10;
      return (undefined4 *)0x0;
    }
    puVar3 = (undefined4 *)FUN_007564e0();
    ExceptionList = local_10;
    return puVar3;
  }
  if (600 < param_1) {
    if (0x4b0 < param_1) {
      if (0x514 < param_1) {
        switch(param_1) {
        case 0x515:
          goto switchD_007476c3_caseD_515;
        default:
          return (undefined4 *)0x0;
        case 0x578:
          ExceptionList = &local_10;
          pvVar2 = _malloc(0xa8);
          local_8 = 2;
          if (pvVar2 == (void *)0x0) {
            ExceptionList = local_10;
            return (undefined4 *)0x0;
          }
          puVar3 = (undefined4 *)FUN_00745040();
          ExceptionList = local_10;
          return puVar3;
        case 0x5dc:
          ExceptionList = &local_10;
          puVar3 = _malloc(0xe0);
          local_8 = 0x15;
          if (puVar3 == (undefined4 *)0x0) {
            ExceptionList = local_10;
            return (undefined4 *)0x0;
          }
          FUN_00760680();
          *puVar3 = FoxUI::FXUITabBox::vftable;
          ExceptionList = local_10;
          return puVar3;
        case 0x5dd:
          ExceptionList = &local_10;
          puVar3 = _malloc(0xd8);
          local_8 = 0x16;
          if (puVar3 == (undefined4 *)0x0) {
            ExceptionList = local_10;
            return (undefined4 *)0x0;
          }
          FUN_0075fed0(puVar3);
          *puVar3 = FoxUI::FXUITabBoxNavigator::vftable;
          ExceptionList = local_10;
          return puVar3;
        case 0x5de:
          ExceptionList = &local_10;
          puVar3 = _malloc(0xa4);
          local_8 = 0x17;
          if (puVar3 == (undefined4 *)0x0) {
            ExceptionList = local_10;
            return (undefined4 *)0x0;
          }
          FUN_00744320();
          *puVar3 = FoxUI::FXUITabBoxContent::vftable;
          ExceptionList = local_10;
          return puVar3;
        }
      }
      if (param_1 != 0x514) {
        switch(param_1) {
        case 0x4b1:
          goto switchD_00747575_caseD_4b1;
        case 0x4b2:
          ExceptionList = &local_10;
          puVar3 = _malloc(0xe8);
          local_8 = 0x10;
          if (puVar3 == (undefined4 *)0x0) {
            ExceptionList = local_10;
            return (undefined4 *)0x0;
          }
          FUN_00471830();
          *puVar3 = FoxUI::FXUIComboBoxListContent::vftable;
          ExceptionList = local_10;
          return puVar3;
        case 0x4b3:
          ExceptionList = &local_10;
          puVar3 = _malloc(0xe0);
          local_8 = 0x12;
          if (puVar3 == (undefined4 *)0x0) {
            ExceptionList = local_10;
            return (undefined4 *)0x0;
          }
          FUN_0075da10();
          *puVar3 = FoxUI::FXUIComboBoxListScrollBar::vftable;
          ExceptionList = local_10;
          return puVar3;
        case 0x4b4:
          ExceptionList = &local_10;
          pvVar2 = _malloc(0x248);
          local_8 = 0x11;
          if (pvVar2 == (void *)0x0) {
            ExceptionList = local_10;
            return (undefined4 *)0x0;
          }
          puVar3 = (undefined4 *)FUN_0041c240();
          ExceptionList = local_10;
          return puVar3;
        default:
          return (undefined4 *)0x0;
        }
      }
      ExceptionList = &local_10;
      puVar3 = _malloc(0xdc);
      local_8 = 0x13;
      if (puVar3 == (undefined4 *)0x0) {
        ExceptionList = local_10;
        return (undefined4 *)0x0;
      }
      FUN_0076be30();
      *puVar3 = FoxUI::FXUIListBox::vftable;
      ExceptionList = local_10;
      return puVar3;
    }
    if (param_1 == 0x4b0) {
      ExceptionList = &local_10;
      pvVar2 = _malloc(0x250);
      local_8 = 0xe;
      if (pvVar2 == (void *)0x0) {
        ExceptionList = local_10;
        return (undefined4 *)0x0;
      }
      puVar3 = (undefined4 *)FUN_0075cb30();
      ExceptionList = local_10;
      return puVar3;
    }
    if (900 < param_1) {
      if (param_1 != 1000) {
        return (undefined4 *)0x0;
      }
      ExceptionList = &local_10;
      pvVar2 = _malloc(0x15c);
      local_8 = 0xd;
      if (pvVar2 == (void *)0x0) {
        ExceptionList = local_10;
        return (undefined4 *)0x0;
      }
      puVar3 = (undefined4 *)FUN_00765430();
      ExceptionList = local_10;
      return puVar3;
    }
    if (param_1 == 900) {
      ExceptionList = &local_10;
      pvVar2 = _malloc(0xdc);
      local_8 = 0xb;
      if (pvVar2 == (void *)0x0) {
        ExceptionList = local_10;
        return (undefined4 *)0x0;
      }
      puVar3 = (undefined4 *)FUN_0075bb00();
      ExceptionList = local_10;
      return puVar3;
    }
    if (param_1 == 700) {
      ExceptionList = &local_10;
      pvVar2 = _malloc(0x248);
      local_8 = 9;
      if (pvVar2 == (void *)0x0) {
        ExceptionList = local_10;
        return (undefined4 *)0x0;
      }
      puVar3 = (undefined4 *)FUN_0076eff0();
      ExceptionList = local_10;
      return puVar3;
    }
    if (param_1 != 800) {
      return (undefined4 *)0x0;
    }
    ExceptionList = &local_10;
    pvVar2 = _malloc(0x24c);
    local_8 = 10;
    if (pvVar2 == (void *)0x0) {
      ExceptionList = local_10;
      return (undefined4 *)0x0;
    }
    puVar3 = (undefined4 *)FUN_00765240();
    ExceptionList = local_10;
    return puVar3;
  }
  if (param_1 == 600) {
    ExceptionList = &local_10;
    pvVar2 = _malloc(0x160);
    local_8 = 8;
    if (pvVar2 == (void *)0x0) {
      ExceptionList = local_10;
      return (undefined4 *)0x0;
    }
    puVar3 = (undefined4 *)FUN_007659c0();
    ExceptionList = local_10;
    return puVar3;
  }
  if (param_1 < 0x65) {
    if (param_1 == 100) {
      ExceptionList = &local_10;
      pvVar2 = _malloc(0xa4);
      local_8 = 1;
      if (pvVar2 == (void *)0x0) {
        ExceptionList = local_10;
        return (undefined4 *)0x0;
      }
      puVar3 = (undefined4 *)FUN_00744320();
      ExceptionList = local_10;
      return puVar3;
    }
    if (param_1 != 0x33) {
      return (undefined4 *)0x0;
    }
    ExceptionList = &local_10;
    pvVar2 = _malloc(0x8c);
    local_8 = 0;
    if (pvVar2 == (void *)0x0) {
      ExceptionList = local_10;
      return (undefined4 *)0x0;
    }
    puVar3 = (undefined4 *)FUN_00755270();
    ExceptionList = local_10;
    return puVar3;
  }
  if (500 < param_1) {
    return (undefined4 *)0x0;
  }
  if (param_1 == 500) {
    ExceptionList = &local_10;
    pvVar2 = _malloc(0x16c);
    local_8 = 7;
    if (pvVar2 == (void *)0x0) {
      ExceptionList = local_10;
      return (undefined4 *)0x0;
    }
    puVar3 = (undefined4 *)FUN_00761150();
    ExceptionList = local_10;
    return puVar3;
  }
  switch(param_1) {
  case 200:
    ExceptionList = &local_10;
    puVar3 = _malloc(0x158);
    local_8 = 3;
    goto LAB_0074710c;
  case 0xc9:
    ExceptionList = &local_10;
    puVar3 = _malloc(0x158);
    local_8 = 0xc;
LAB_0074710c:
    if (puVar3 != (undefined4 *)0x0) {
      FUN_00754880();
      *puVar3 = FoxUI::FXUIStatic::vftable;
      ExceptionList = local_10;
      return puVar3;
    }
    break;
  case 300:
    ExceptionList = &local_10;
    pvVar2 = _malloc(0x194);
    local_8 = 4;
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0075bf50();
      ExceptionList = local_10;
      return puVar3;
    }
    break;
  case 0x12d:
    ExceptionList = &local_10;
    pvVar2 = _malloc(0x248);
    local_8 = 5;
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_00744ba0();
      ExceptionList = local_10;
      return puVar3;
    }
    break;
  case 0x12e:
    ExceptionList = &local_10;
    pvVar2 = _malloc(0x194);
    local_8 = 0x18;
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0042aeb0();
      ExceptionList = local_10;
      return puVar3;
    }
    break;
  case 0x12f:
    ExceptionList = &local_10;
    pvVar2 = _malloc(0x194);
    local_8 = 0x19;
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0042ac20();
      ExceptionList = local_10;
      return puVar3;
    }
    break;
  case 0x130:
    ExceptionList = &local_10;
    pvVar2 = _malloc(0x194);
    local_8 = 0x1a;
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0042a990();
      ExceptionList = local_10;
      return puVar3;
    }
    break;
  case 0x131:
    ExceptionList = &local_10;
    pvVar2 = _malloc(0x194);
    local_8 = 0x1b;
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0042a700();
      ExceptionList = local_10;
      return puVar3;
    }
    break;
  case 0x132:
    ExceptionList = &local_10;
    pvVar2 = _malloc(0x194);
    local_8 = 0x1c;
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0042a470();
      ExceptionList = local_10;
      return puVar3;
    }
    break;
  case 0x133:
    ExceptionList = &local_10;
    pvVar2 = _malloc(0x194);
    local_8 = 0x1d;
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0042a090();
      ExceptionList = local_10;
      return puVar3;
    }
    break;
  case 0x134:
    ExceptionList = &local_10;
    pvVar2 = _malloc(0x194);
    local_8 = 0x1e;
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_00429e00();
      ExceptionList = local_10;
      return puVar3;
    }
    break;
  case 0x135:
    ExceptionList = &local_10;
    pvVar2 = _malloc(0x194);
    local_8 = 0x1f;
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_00429b70();
      ExceptionList = local_10;
      return puVar3;
    }
    break;
  case 400:
    ExceptionList = &local_10;
    pvVar2 = _malloc(0xe0);
    local_8 = 6;
    if (pvVar2 != (void *)0x0) {
      puVar3 = (undefined4 *)FUN_0075da10();
      ExceptionList = local_10;
      return puVar3;
    }
  }
  ExceptionList = local_10;
  return (undefined4 *)0x0;
switchD_00747e40_caseD_c47d:
  ExceptionList = &local_10;
  pvVar2 = _malloc(0x114);
  local_8 = 0x3c;
  if (pvVar2 == (void *)0x0) {
    ExceptionList = local_10;
    return (undefined4 *)0x0;
  }
  puVar3 = (undefined4 *)FUN_0074c150();
  ExceptionList = local_10;
  return puVar3;
switchD_00747859_caseD_c351:
  ExceptionList = &local_10;
  pvVar2 = _malloc(0x100);
  local_8 = 0x22;
  if (pvVar2 == (void *)0x0) {
    ExceptionList = local_10;
    return (undefined4 *)0x0;
  }
  puVar3 = (undefined4 *)FUN_0075b310();
  ExceptionList = local_10;
  return puVar3;
switchD_007476c3_caseD_515:
  ExceptionList = &local_10;
  puVar3 = _malloc(0xe8);
  local_8 = 0x14;
  if (puVar3 == (undefined4 *)0x0) {
    ExceptionList = local_10;
    return (undefined4 *)0x0;
  }
  FUN_0076bf20();
  *puVar3 = FoxUI::FXUIListBoxContent::vftable;
  ExceptionList = local_10;
  return puVar3;
switchD_00747575_caseD_4b1:
  ExceptionList = &local_10;
  puVar3 = _malloc(0xdc);
  local_8 = 0xf;
  if (puVar3 == (undefined4 *)0x0) {
    ExceptionList = local_10;
    return (undefined4 *)0x0;
  }
  FUN_0075d240();
  *puVar3 = FoxUI::FXUIComboBoxList::vftable;
  ExceptionList = local_10;
  return puVar3;
}

