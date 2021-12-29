# Game files structure

## Galaxies
	

# Galaxy Editor

## Edit map objects
- General objects
- Areas
- Cutscenes?
- Camera cubes?
- Zones
- Gravity
	
## Edit mode for each object type
The edit mode determines how and which objects can be edited
in the 3D view. Everything can also be edited in the designated panels
regardless of the current edit mode.

### Object mode
Allows editing of normal objects. Other objects like areas and zones
can not be edited in the 3D view in this mode.

### Area mode
Allows editing of areas only. Other objects can not be edited in
the 3D view in this mode.

### Cutscene mode?

### Camera mode?

### Zone mode
Allows moving of each zone with a gizmo.
All objects belonging to the zone will be moved relative to the zone.
Zones can also be moved in the zones panel, but without a gizmo.
Optional feature: Zones can be added and removed in zone mode?

### Gravity mode?
	
## 3D view
Objects can be moved in the 3D view using transformation gizmos.
Shortcuts can be used to perform certain actions.
For example, pressing Shift+A will open up a menu from which an object can be selected that will
be placed into the map (like in Blender).

In the 3D view the user can select a zone (combo box) that will be used for edits. By default, the main zone is set.
It is only possible to edit objects that are in the selected zone. Objects in other zones can not be edited.
In order to edit objects in a different zone, the corresponding zone must be selected.
If a zone is selected that is also used in another galaxy then a warning will be shown.
The warning should include the options `Don't show again` and `Don't show again in this session` or similar.

The 3D view should have filtering options to select which objects should be shown or not.
For example there should be the options
`Transparency of objects in other zones` and `Transparency of objects in other layers`.

## Object hierarchy panel
The object hierarchy panel shows all objects in the current zone.
Only objects in the selected zone should be shown.
Objects are sorted by type (General, Area, ...).
It can also be used to select objects and to move the camera to the position of the selected object.

## Zones panel
Zones are displayed as a list / table. Here, each zone's properties like position and rotation can be changed,
regardless of the selected zone in the 3D view or whether the user is in zone mode or not.
Zones can be added or removed. When removing a zone, the user will be asked whether to delete the zone from the
file system or to just remove it from the galaxy.
When adding a zone, the user will be asked whether to create a brand new zone or to import an already existing
zone from the file system (i. e. from another galaxy). If the user chooses to create a brand new zone,
they will be asked for the name of the new zone.